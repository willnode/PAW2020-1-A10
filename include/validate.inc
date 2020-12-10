<?php

    function required(&$error, $field_list, $field_name)
    {
        if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
            $error = $field_name . " is Required!";
        } else {
            $error = "";
        }
    }

    function validateName(&$error, $field_list, $field_name)
    {
        $pattern = "/^[a-zA-Z '-]+$/"; // format surname (alfabet)
        if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
            $error = $field_name . " is Required!";
        } else if (!preg_match($pattern, $field_list[$field_name])) {
            $error = "Must contain alphabet only";
        } else {
            $error = "";
        }
    }

    function ValidateEmail(&$error, $field_list, $field_name)
    {
        if (empty($field_list[$field_name])) {
            $error = "Email is Required!";
        } else if (!filter_var($field_list[$field_name], FILTER_VALIDATE_EMAIL)) {
            $error = "Invalid email address";
        } else {
            $error = "";
        }
    }

    function validatePass(&$error, $field_list, $field_name)
    {
        if (empty($field_list[$field_name])) {
            $error = "Password is required";
        } else   if (strlen($field_list[$field_name]) < 8) {
            $error = "Password is less than 8 character long";
        } else if ((preg_match("/^[a-zA-Z]*$/", $field_list[$field_name])) || (preg_match("/^[0-10]*$/", $field_list[$field_name]))) {
            $error = "Must contain alphabet & numeric";
        } else {
            $error = "";
        }
    }

    function validateConfirm(&$error, $field_list, $field_name1, $field_name2)
    {
        if (empty($field_list[$field_name1])) {
            $error = "Confirm password is required";
        } else if ($field_list[$field_name1] != $field_list[$field_name2]) {
            $error = "Password do not match!";
        } else {
            $error = "";
        }
    }
    ?>
