<?php
session_start();
unset($_SESSION['id']);
unset($_SESSION['email']);
unset($_SESSION['name']);
unset($_SESSION['bio']);
unset($_SESSION['type']);
header('location:index.php');
