<?php
require 'include/adminPermission.inc';
include "include/koneksi.inc";
$idtopic=$_GET['topik'];
$query = $dbc->prepare("SELECT * FROM topic WHERE topic_id = :topic");
$query->bindValue(":topic", $idtopic);
$query->execute();
$topic=$query->fetch();
$query = $dbc->prepare("SELECT * FROM thread WHERE topic_id = :topic");
$query->bindValue(":topic", $idtopic);
$query->execute();
$threads=$query->fetchAll();
include "view/topik.inc";