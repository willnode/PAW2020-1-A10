<?php

function required(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $error = $field_name . " is Required!";
    } else {
        $error = "";
    }
}

function validateName(&$error, $field_list, $field_name)
{
    $pattern = "/^[a-zA-Z '-]+$/"; // format surname (alfabet)
    // cek apakah field kosong
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $error = $field_name . " is Required!";
        // cek apakah inputan hanya terdiri dari huruf
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $error = "Must contain alphabet only";
    } else {
        $error = "";
    }
}

function ValidateEmail(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name])) {
        $error = "Email is Required!";
        // cek apakah email sesuai format
    } else if (!filter_var($field_list[$field_name], FILTER_VALIDATE_EMAIL)) {
        $error = "Invalid email address";
    } else {
        $error = "";
    }
}

function validatePass(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name])) {
        $error = "Password is required";
        // cek apakah panjang password kurang dari 8 karakter
    } else   if (strlen($field_list[$field_name]) < 8) {
        $error = "Password is less than 8 character long";
        // cek apakah password sudah terdiri dari alpha numeric
    } else if ((preg_match("/^[a-zA-Z]*$/", $field_list[$field_name])) || (preg_match("/^[0-10]*$/", $field_list[$field_name]))) {
        $error = "Must contain alphabet & numeric";
    } else {
        $error = "";
    }
}

function validateConfirm(&$error, $field_list, $field_name1, $field_name2)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name1])) {
        $error = "Confirm password is required";
        // cek apakah password sama
    } else if ($field_list[$field_name1] != $field_list[$field_name2]) {
        $error = "Password do not match!";
    } else {
        $error = "";
    }
}
