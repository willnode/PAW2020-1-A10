<?php

function required(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $error = " *" . $field_name . " diperlukan!";
    } else {
        $error = "";
    }
}

function validateName(&$error, $field_list, $field_name)
{
    $pattern = "/^[a-zA-Z '-]+$/"; // format surname (alfabet)
    // cek apakah field kosong
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $error = " *" . $field_name . " diperlukan!";
        // cek apakah inputan hanya terdiri dari huruf
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $error = " *Harus berisi alfabet saja";
    } else {
        $error = "";
    }
}

function ValidateEmail(&$error, $field_list, $field_name)
{
    include "koneksi.inc";
    $query = $dbc->prepare("SELECT * FROM user WHERE email=:email");
    $query->bindValue(":email", $field_list[$field_name]);
    $query->execute();
    // cek apakah field kosong
    if (empty($field_list[$field_name])) {
        $error = " *Email diperlukan!";
        // cek apakah email sesuai format
    } else if (!filter_var($field_list[$field_name], FILTER_VALIDATE_EMAIL)) {
        $error = " *Email tidak valid";
        //cek apakah data yang diisikan belum pernah terdata
    } else if ($query->rowCount() > 0) {
        $error = " *Email sudah didaftarkan";
    } else {
        $error = "";
    }
}

function validatePass(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name])) {
        $error = " *Password diperlukan";
        // cek apakah panjang password kurang dari 8 karakter
    } else   if (strlen($field_list[$field_name]) < 8) {
        $error = "*Password harus 8 karakter keatas";
        // cek apakah password sudah terdiri dari alpha numeric
    } else if ((preg_match("/^[a-zA-Z]*$/", $field_list[$field_name])) || (preg_match("/^[0-10]*$/", $field_list[$field_name]))) {
        $error = " *Harus ada karakter alfabet dan angka";
    } else {
        $error = "";
    }
}

function validateConfirm(&$error, $field_list, $field_name1, $field_name2)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name1])) {
        $error = " *Konfirmasi password diperlukan";
        // cek apakah password sama
    } else if ($field_list[$field_name1] != $field_list[$field_name2]) {
        $error = " *Password tidak sama!";
    } else {
        $error = "";
    }
}

function validateAvatar(&$error, $field_name, $images)
{
    $name = $images['avatar']['name']; //mengambil nama file
    $jenis_gambar = $images['avatar']['type']; //mengambil ekstensi file
    $ukuran = $images['avatar']['size']; //mengambil ukuran file
    $lokasi = $images['avatar']['tmp_name']; //mengambil direktori asal
    if (!empty($name)) {
        //mengecek apakah format sesuai
        if ($jenis_gambar == "image/jpeg" || $jenis_gambar == "image/jpg" || $jenis_gambar == "image/png") {
            //mengecek ukuran apakah melebihi 5mb
            if ($ukuran <= 5000000) {
                $error = "";
            } else {
                $error = " *Ukuran file terlalu besar";
            }
        } else {
            //mengecek apakah format gambar sesuai
            $error = " *Format file harus .jpg .jpeg .png";
        }
    }
}


function ValidateEmailLog(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name])) {
        $error = " *Email diperlukan!";
        // cek apakah email sesuai format
    } else if (!filter_var($field_list[$field_name], FILTER_VALIDATE_EMAIL)) {
        $error = " *Email tidak valid";
    } else {
        $error = "";
    }
}


function oldPassword(&$error, $field_list, $field_name, $old_pass)
{
    //cek apakah field kosong
    if (empty($field_list[$field_name])) {
        $error = " *Password lama diperlukan";
        //cek apakah password yang di input sama dengan password lama
    } else if ($old_pass == 0) {
        $error = "*Password tidak sama";
    } else {
        $error = "";
    }
}
