<?php

// Menampilkan thread atau memposting jawaban expert

include "include/koneksi.inc";
include "include/validate.inc";
if ($_GET['id']) {
    if ($_POST) {
        required($answerErr, $_POST, 'answer');

        $statement = $dbc->prepare("INSERT INTO answer (user_id, thread_id, answer, time) VALUES (:user_id, :thread_id, :answer, :time)");
        $statement->bindValue(':user_id', $_SESSION['id']);
        $statement->bindValue(':thread_id', $_GET['id']);
        $statement->bindValue(':answer', $_POST['answer']);
        $statement->bindValue(':time', date('Y-m-d H:i:s'));
        $statement->execute();
        // balik ke mode GET
        header('Location: ?id=' . $_GET['id']);
    }
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