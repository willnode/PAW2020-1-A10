<?php
require_once "include/koneksi.inc";
require_once "include/validate.inc";

// deklarasi valiable validasi
$nameErr = $avatarErr = $bioErr = $emailErr = $passwordErr = $confirmErr =  "";
if (isset($_POST['submit'])) {
    validateName($nameErr, $_POST, "name"); //validasi inputan nama required, alphabet
    ValidateEmail($emailErr, $_POST, "email"); //validasi email
    validatePass($passwordErr, $_POST, "password"); //validasi password
    required($bioErr, $_POST, "bio"); //validasi bio
    validateAvatar($avatarErr, 'avatar', $_FILES); //validasi avatar/profile image
    validateConfirm($confirmErr, $_POST, "confirm", "password"); //validasi confirm password
    //cek jika sudah tidak ada error
    if ($nameErr == "" && $emailErr == "" && $passwordErr == "" && $confirmErr == "" && $bioErr == "" && $avatarErr == "") {
        $name = $_FILES['avatar']['name']; //mengambil nama file
        $lokasi = $_FILES['avatar']['tmp_name']; //mengambil direktori asal
        $statement = $dbc->prepare("INSERT INTO user (email, password, name, bio, avatar, type) VALUES (:email, SHA2(:password, 0), :name,:bio,:avatar, :type)");
        $statement->bindValue(':email', $_POST['email']);
        $statement->bindValue(':password', $_POST['password']);
        $statement->bindValue(':name', $_POST['name']);
        $statement->bindValue(":bio", $_POST['bio']);
        $statement->bindValue(":avatar", $name);
        $statement->bindValue(":type", $_POST['type']);
        $statement->execute();
        move_uploaded_file($lokasi, "image/profile/" . $name);
        header("location:index.php");
    }
}

include "view/register.inc";
