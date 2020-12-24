<?php

// Edit jawaban expert dari thread
// NB: Edit thread tidak disini, lihat thread_post.php

require 'include/adminPermission.inc';
include "include/koneksi.inc";

$questionErr = $titleErr = $topicErr = $answerErr = '';

if ($_POST) {
}

if (isset($_GET['answer_id'])) {
    // Ambil answers dari thread yang sama
    $query = $dbc->prepare("SELECT * FROM answer WHERE answer_id = :answer");
    $query->bindValue(":answer", $id);
    $query->execute();
    $answer = $query->fetch();
}
