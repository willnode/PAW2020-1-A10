<?php

// Halaman User Ganti Profil Mereka Sendiri

require 'include/adminPermission.inc';
include "include/koneksi.inc";
include "include/validate.inc";

// deklarasi valiable validasi
$nameErr =  $bioErr =  $passwordErr = $avatarErr =  "";
if (isset($_POST['submit'])) {
    validateName($nameErr, $_POST, "name"); //validasi inputan name required, alphabet
    required($bioErr, $_POST, "bio"); //validasi bio
    validateAvatar($avatarErr, 'avatar', $_FILES); //validasi avatar/profile image
    //cek jika sudah tidak ada error
    if ($nameErr ==  "" && $bioErr == "" && $avatarErr == "") {
        $name = $_FILES['avatar']['name']; //mengambil name file
        $lokasi = $_FILES['avatar']['tmp_name']; //mengambil direktori asal
        //cek apakah data nama kosong atau tidak
        if (empty($name)) {
            $statement = $dbc->prepare("UPDATE `user` SET name=:name,bio=:bio WHERE user_id=:id"); //menyiapkan query
        } else {
            move_uploaded_file($lokasi, "image/profile/" . $name); //memindah file gambar yang diupload ke sub folder profila pada folder image
            $statement = $dbc->prepare("UPDATE `user` SET name=:name,bio=:bio,avatar=:avatar WHERE user_id=:id");  //menyiapkan query
            $statement->bindValue(":avatar", $name); //menghubungkan data dengan variabel
        }
        //menghubungkan data dengan variabel
        $statement->bindValue(':name', $_POST['name']);
        $statement->bindValue(":bio", $_POST['bio']);
        $statement->bindValue(":id", $_POST['id']);
        //menjalankan query
        $statement->execute();
        //menjalankan session
        $_SESSION['name'] = $_POST['name'];
        $_SESSION['bio'] = $_POST['bio'];
        header("location:index.php"); //akan diarahkan ke halaman index.php
        exit;
    }
}
include "view/edit_profile.inc"; //include file edit_profile.inc pada volder view
