<?php

// Edit jawaban expert dari thread
// NB: Edit thread tidak disini, lihat thread_post.php

require 'include/adminPermission.inc';
include "include/koneksi.inc";

$answerErr = '';

if (isset($_GET['answer_id'])) {
    $id = $_GET['answer_id'];
    // Ambil answers dari thread yang sama
    $query = $dbc->prepare("SELECT * FROM answer WHERE answer_id = :answer");
    $query->bindValue(":answer", $id);
    $query->execute();
    $answer = $query->fetch();

    if ($_POST) {
        // Ambil answers dari thread yang sama
        $query = $dbc->prepare("UPDATE answer SET answer=:text WHERE answer_id = :answer");
        $query->bindValue(":answer", $id);
        $query->bindValue(":text", $_POST['answer']);
        $query->execute();
        header("Location: thread.php?id=$answer[thread_id]");
    }

    include "view/thread_edit.inc";
}
