<?php
session_start(); //memulai session
//menghapus variabel session
unset($_SESSION['id']);
unset($_SESSION['email']);
unset($_SESSION['name']);
unset($_SESSION['bio']);
unset($_SESSION['type']);
//end
header('location:index.php'); //akan diarahkan ke index.php
