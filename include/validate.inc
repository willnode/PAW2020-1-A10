<?php

function required(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $error = " *" . $field_name . " is required!";
    } else {
        $error = "";
    }
}

function validateName(&$error, $field_list, $field_name)
{
    $pattern = "/^[a-zA-Z '-]+$/"; // format surname (alfabet)
    // cek apakah field kosong
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $error = " *" . $field_name . " is required!";
        // cek apakah inputan hanya terdiri dari huruf
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $error = " *must contain alphabet only";
    } else {
        $error = "";
    }
}

function ValidateEmail(&$error, $field_list, $field_name)
{
    include "koneksi.inc";
    // cek apakah field kosong
    $query = $dbc->prepare("SELECT * FROM user WHERE email=:email");
    $query->bindValue(":email", $field_list[$field_name]);
    $query->execute();
    if (empty($field_list[$field_name])) {
        $error = " *email is required!";
        // cek apakah email sesuai format
    } else if (!filter_var($field_list[$field_name], FILTER_VALIDATE_EMAIL)) {
        $error = " *invalid email address";
    } else if ($query->rowCount() > 0) {
        $error = " *Email already exist";
    } else {
        $error = "";
    }
}

function validatePass(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name])) {
        $error = " *password is required";
        // cek apakah panjang password kurang dari 8 karakter
    } else   if (strlen($field_list[$field_name]) < 8) {
        $error = "Password is less than 8 character long";
        // cek apakah password sudah terdiri dari alpha numeric
    } else if ((preg_match("/^[a-zA-Z]*$/", $field_list[$field_name])) || (preg_match("/^[0-10]*$/", $field_list[$field_name]))) {
        $error = " *must contain alphabet & numeric";
    } else {
        $error = "";
    }
}

function validateConfirm(&$error, $field_list, $field_name1, $field_name2)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name1])) {
        $error = " *confirm password is required";
        // cek apakah password sama
    } else if ($field_list[$field_name1] != $field_list[$field_name2]) {
        $error = " *password do not match!";
    } else {
        $error = "";
    }
}

function validateAvatar(&$error, $field_name, $images)
{
    // cek apakah field kosong
    if (empty($images)) {
        $error = " *" . $field_name . " is required";
    } else {
        $name = $images['avatar']['name']; //mengambil nama file
        $jenis_gambar = $images['avatar']['type']; //mengambil ekstensi file
        $ukuran = $images['avatar']['size']; //mengambil ukuran file
        $lokasi = $images['avatar']['tmp_name']; //mengambil direktori asal
        //mengecek apakah format sesuai
        if ($jenis_gambar == "image/jpeg" || $jenis_gambar == "image/jpg" || $jenis_gambar == "image/png") {
            //mengecek ukuran apakah melebihi 5mb
            if ($ukuran <= 5000000) {
                $error = "";
            } else {
                $error = " *File size is too large";
            }
        } else {
            $error = " *The format file must be .jpg .jpeg .png";
        }
    }
}

function ValidateEmailLog(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name])) {
        $error = " *email is required!";
        // cek apakah email sesuai format
    } else if (!filter_var($field_list[$field_name], FILTER_VALIDATE_EMAIL)) {
        $error = " *invalid email address";
    } else {
        $error = "";
    }
}
