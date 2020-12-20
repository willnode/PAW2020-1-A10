<?php
//menyisipkan file .inc
require 'include/adminPermission.inc';
include "include/koneksi.inc";

$idtopic=$_GET['topik']; //deklarasi variabel idtopic

//prepared statement
$query = $dbc->prepare("SELECT * FROM topic WHERE topic_id = :topic"); //menyiapkan query select all pada tabel topic
$query->bindValue(":topic", $idtopic);
$query->execute(); //menjalankan query
$topic=$query->fetch();

//prepared statement
$query = $dbc->prepare("SELECT * FROM thread WHERE topic_id = :topic"); //menyiapkan query select all pada tabel thread
$query->bindValue(":topic", $idtopic);
$query->execute(); //menjalankan query
$threads=$query->fetchAll();
include "view/topik.inc"; //menyisipkan file topik.inc pada folder view