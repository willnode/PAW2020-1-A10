<?php

// Halaman Logout, Hasilnya langsung redirect

session_start(); // mulai session

session_destroy(); // hapus session

header('location:index.php'); // arahkan ke index.php
