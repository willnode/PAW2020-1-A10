<?php
session_start();
if (!isset($_SESSION['isAdmin'])) {
    header("location:login.php");
    exit;
}
