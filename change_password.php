<?php

require 'include/adminPermission.inc';
include "include/koneksi.inc";
include "include/validate.inc";

// deklarasi valiable validasi
$oldPassErr =  $newPassErr =  $confirmPassErr =  "";
if (isset($_POST['submit'])) {
    $query = $dbc->prepare("SELECT * FROM user WHERE password=SHA2(:old_password,0)");
    $query->bindValue(":old_password", $_POST['old_password']); //password dari form
    $query->execute();
    oldPassword($oldPassErr, $_POST, "old_password", $query->rowCount()); //validasi inputan nama required, alphabet
    validatePass($newPassErr, $_POST, "new_password"); //validasi new password
    validateConfirm($confirmPassErr, $_POST, "new_password", "confirm");
    //cek jika sudah tidak ada error
    if ($oldPassErr ==  "" && $newPassErr == "" && $confirmPassErr == "") {
        $statement = $dbc->prepare("UPDATE user SET password=SHA2(:password,0) WHERE user_id=:id");
        $statement->bindValue(':password', $_POST['new_password']);
        $statement->bindValue(":id", $_POST['id']);
        $statement->execute();
        header("location:index.php");
    }
}
include "view/change_password.inc";
