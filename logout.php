<?php
session_start();
unset($_SESSION['email']);
unset($_SESSION['nama']);
unset($_SESSION['bio']);
unset($_SESSION['type']);
header('location:index.php');
