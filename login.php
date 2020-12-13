<?php

include "include/koneksi.inc";
include "include/validate.inc";

function checkPassword($email, $password)
{
    global $dbc;
    $query = $dbc->prepare("SELECT * FROM user WHERE email = :email AND password = SHA2(:password,0)");
    $query->bindvalue(":email", $email);
    $query->bindValue(":password", $password);
    $query->execute();
    return $query->rowCount() > 0;
}
$error = "";
$emailErr = $passErr = ""; //deklarasi variabel validasi inputan login
if (isset($_POST['login'])) {
    ValidateEmailLog($emailErr, $_POST, "email");
    required($passErr, $_POST, 'password');
    if ($emailErr == "" && $passErr == "") {
        if (checkPassword($_POST["email"], $_POST['password'])) {
            session_start();
            $query = $dbc->prepare("SELECT * FROM user WHERE email=:email");
            $query->bindValue(":email", $_POST['email']);
            $query->execute();
            foreach ($query as $row) {
                $_SESSION['email'] = $row['email'];
                $_SESSION['nama'] = $row['nama'];
                $_SESSION['bio'] = $row['bio'];
                $_SESSION['type'] = $row['type'];
            }
            header("location:beranda.php");
            exit();
        } else {
            $error = "* Email or password didn't match";
        }
    }
}

include "view/login.inc";
