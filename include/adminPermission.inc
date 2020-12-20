<?php
session_start(); //memulai session
if (!isset($_SESSION['type'])) {
    header("location:login.php"); //akan diarahkan ke halaman login.php
    exit;
}
