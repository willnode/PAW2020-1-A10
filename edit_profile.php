<?php

require 'include/adminPermission.inc';
include "include/koneksi.inc";
include "include/validate.inc";

// deklarasi valiable validasi
$nameErr =  $bioErr =  $passwordErr = $avatarErr =  "";
if (isset($_POST['submit'])) {
    validateName($nameErr, $_POST, "name"); //validasi inputan name required, alphabet
    required($bioErr, $_POST, "bio"); //validasi bio
    updateAvatar($avatarErr, 'avatar', $_FILES); //validasi avatar/profile image
    //cek jika sudah tidak ada error
    if ($nameErr ==  "" && $bioErr == "" && $avatarErr == "") {
        $name = $_FILES['avatar']['name']; //mengambil name file
        $lokasi = $_FILES['avatar']['tmp_name']; //mengambil direktori asal
        if (empty($name)) {
            $statement = $dbc->prepare("UPDATE `user` SET name=:name,bio=:bio WHERE user_id=:id");
        } else {
            move_uploaded_file($lokasi, "image/profile/" . $name);
            $statement = $dbc->prepare("UPDATE `user` SET name=:name,bio=:bio,avatar=:avatar WHERE user_id=:id");
            $statement->bindValue(":avatar", $name);
        }
        $statement->bindValue(':name', $_POST['name']);
        $statement->bindValue(":bio", $_POST['bio']);
        $statement->bindValue(":id", $_POST['id']);
        $statement->execute();
        $_SESSION['name'] = $_POST['name'];
        $_SESSION['bio'] = $_POST['bio'];
        header("location:index.php");
    }
}
include "view/edit_profile.inc";