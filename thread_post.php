<?php

// Tambah atau edit pertanyaan/thread dari client

require 'include/adminPermission.inc';
include "include/koneksi.inc";
include "include/validate.inc";


$questionErr = $titleErr = $topicErr = '';

if ($_POST) {
    // Thread baru
    required($questionErr, $_POST, 'question');
    required($titleErr, $_POST, 'title');
    required($topicErr, $_POST, 'topic');

    if ($questionErr ==  "" && $titleErr == "" && $topicErr == "") {
        // Mode POST, proses..
        if (isset($_GET['id'])) {
            $statement = $dbc->prepare("UPDATE thread SET topic_id=:topic_id, title=:title, question=:question WHERE thread_id=:thread_id");
            $statement->bindValue(':thread_id', $_GET['id']);
            $statement->bindValue(':topic_id', $_POST['topic']);
            $statement->bindValue(':title', $_POST['title']);
            $statement->bindValue(':question', $_POST['question']);
            $statement->execute();
            // balik ke halaman view thread
            header('Location: thread.php?id=' . $_GET['id']);
            exit;
        } else {
            $statement = $dbc->prepare("INSERT INTO thread (user_id, topic_id, title, question, time) VALUES (:user_id, :topic_id, :title,:question,:time)");
            $statement->bindValue(':user_id', $_SESSION['id']);
            $statement->bindValue(':topic_id', $_POST['topic']);
            $statement->bindValue(':title', $_POST['title']);
            $statement->bindValue(':question', $_POST['question']);
            $statement->bindValue(':time', date('Y-m-d H:i:s'));
            $statement->execute();
            // balik ke halaman view thread
            header('Location: thread.php?id=' . $dbc->lastInsertId());
            exit;
        }
    }
}

if (isset($_GET['id'])) {
    // Ambil thread dari DB
    $query = $dbc->prepare("SELECT * FROM thread WHERE thread_id = :thread");
    $query->bindValue(":thread", $_GET['id']);
    $query->execute();
    $thread = $query->fetch();
} else {
    $thread = [
        'title' => '',
        'question' => '',
        'topic_id' => $_GET['topic'] ?? '',
    ];
}

// Form buat baru
$query = $dbc->prepare("SELECT * FROM topic");
$query->execute();
$topics = $query->fetchAll();
include "view/thread_new.inc";
