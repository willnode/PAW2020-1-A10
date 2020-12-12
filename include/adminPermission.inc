<?php
session_start();
if (!isset($_SESSION['type'])) {
    header("location:login.php");
    exit;
}
