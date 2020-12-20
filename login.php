<?php
//menyisipkan file .inc
include "include/koneksi.inc";
include "include/validate.inc";

function checkPassword($email, $password) 
{
    global $dbc; //penggunaan global variabel 
    $query = $dbc->prepare("SELECT * FROM user WHERE email = :email AND password = SHA2(:password,0)"); //menyiapkan quert select pada kolom user
    $query->bindValue(":email", $email); 
    $query->bindValue(":password", $password);
    $query->execute(); //query dijalankan
    return $query->rowCount() > 0; 
}
$error = "";
$emailErr = $passErr = ""; //deklarasi variabel validasi inputan login
if (isset($_POST['login'])) {
    ValidateEmailLog($emailErr, $_POST, "email"); //validasi email pada login
    required($passErr, $_POST, 'password'); //validasi password
    //cek jika sudah tidak ada error
    if ($emailErr == "" && $passErr == "") {
        //cek data email dan password sudah 
        if (checkPassword($_POST["email"], $_POST['password'])) { 
            session_start(); //memulai session pada server
            $query = $dbc->prepare("SELECT * FROM user WHERE email=:email"); //menyiapkan query select pada tabel user
            $query->bindValue(":email", $_POST['email']); //menghubungkan data dengan variabel
            $query->execute(); //query dijalankan
            //perulangan 
            foreach ($query as $row) {
                $_SESSION['id'] = $row['user_id'];
                $_SESSION['email'] = $row['email'];
                $_SESSION['name'] = $row['name'];
                $_SESSION['bio'] = $row['bio'];
                $_SESSION['type'] = $row['type'];
            }
            header("location:beranda.php"); //akan diarahkan ke halaman beranda.php
            exit(); //keluar dari halaman ini
        } else {
            $error = "* Email or password didn't match"; //validasi email dan password jika tidak sesuai dengan data pada database
        }
    }
}

include "view/login.inc"; //menyisipkan file login.inc pada folder view
