<?php
    require_once "include/koneksi.inc";
    require_once "include/validate.inc";

    $nameErr = $avatarErr = $bioErr = $emailErr = $passwordErr = $confirmErr =  "";
    if (isset($_POST['submit'])) {
        validateName($nameErr, $_POST, "name");
        ValidateEmail($emailErr, $_POST, "email");
        validatePass($passwordErr, $_POST, "password");
        required($bioErr, $_POST, "bio");
        // required($avatarErr, $_POST, "avatar");
        validateConfirm($confirmErr, $_POST, "confirm", "password");
        if ($nameErr == "" && $emailErr == "" && $passwordErr == "" && $confirmErr == "" && $bioErr == "") {
            $statement = $dbc->prepare("INSERT INTO user (email, password, nama, bio, avatar, type) VALUES (:email, SHA2(:password, 0), :nama,:bio,:avatar, :type)");
            $statement->bindValue(':email', $_POST['email']);
            $statement->bindValue(':password', $_POST['password']);
            $statement->bindValue(':nama', $_POST['name']);
            $statement->bindValue(":bio", $_POST['bio']);
            $statement->bindValue(":avatar", $_POST['avatar']);
            $statement->bindValue(":type", $_POST['type']);
            $statement->execute();
            header("location:index.php");
        }
    }

    include "view/register.inc";
