<?php
//menyisipkan file .inc
require 'include/adminPermission.inc';
include "include/koneksi.inc";
include "include/validate.inc";


$questionErr = $titleErr = $topicErr = $answerErr = '';

if ($_POST) {
    // Mode POST, proses..
    if (isset($_GET['id'])) {
        // Posting Answer Baru
        required($answerErr, $_POST, 'answer');

        $statement = $dbc->prepare("INSERT INTO answer (user_id, thread_id, answer, time) VALUES (:user_id, :thread_id, :answer, :time)");
        $statement->bindValue(':user_id', $_SESSION['id']);
        $statement->bindValue(':thread_id', $_GET['id']);
        $statement->bindValue(':answer', $_POST['answer']);
        $statement->bindValue(':time', date('Y-m-d H:i:s'));
        $statement->execute();
        // redirect ke mode GET
        header('Location: ?id=' . $_GET['id']);
    } else {
        // Thread baru
        required($questionErr, $_POST, 'question');
        required($titleErr, $_POST, 'title');
        required($topicErr, $_POST, 'topic');

        $statement = $dbc->prepare("INSERT INTO thread (user_id, topic_id, title, question, time) VALUES (:user_id, :topic_id, :title,:question,:time)");
        $statement->bindValue(':user_id', $_SESSION['id']);
        $statement->bindValue(':topic_id', $_POST['topic']);
        $statement->bindValue(':title', $_POST['title']);
        $statement->bindValue(':question', $_POST['question']);
        $statement->bindValue(':time', date('Y-m-d H:i:s'));
        $statement->execute();
        // redirect ke halaman Thread ber-ID
        header('Location: ?id=' . $dbc->lastInsertId());
    }
    exit;
}

if (isset($_GET['id'])) {
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
    // Form buat baru
    $query = $dbc->prepare("SELECT * FROM topic");
    $query->execute();
    $topics = $query->fetchAll();
    include "view/thread_new.inc";
}
