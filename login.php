<?php

    include "include/koneksi.inc";

    function checkPassword($email, $password)
    {
        global $dbc;
        $query = $dbc->prepare("SELECT * FROM user WHERE email = :email AND password = SHA2(:password,0)");
        $query->bindvalue(":email", $email);
        $query->bindValue(":password", $password);
        $query->execute();
        return $query->rowCount() > 0;
    }

    if (isset($_POST['login'])) {
        if (checkPassword($_POST["email"], $_POST['password'])) {
            session_start();
            $_SESSION['email'] = $_POST['email'];
            $_SESSION['isAdmin'] = true;
            header("location:beranda.php");
            exit();
        }
    }

    include "view/login.inc";
