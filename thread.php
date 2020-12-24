<?php

// Menampilkan thread atau memposting jawaban expert

if ($_GET['id']) {
    // Ambil thread dari DB
    $id = $_GET['id'];
    $query = $dbc->prepare("SELECT * FROM thread JOIN user ON thread.user_id = user.user_id WHERE thread_id = :thread");
    $query->bindValue(":thread", $id);
    $query->execute();
    $thread = $query->fetch();
    // Ambil answers dari thread yang sama
    $query = $dbc->prepare("SELECT * FROM answer JOIN user ON answer.user_id = user.user_id WHERE thread_id = :thread");
    $query->bindValue(":thread", $id);
    $query->execute();
    $answers = $query->fetchAll();
    include "view/thread_view.inc";
} else {
    // Arahkan ke form thread baru
    header('Location: thread_post.php');
}