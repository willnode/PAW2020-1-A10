<?php
require 'include/adminPermission.inc';
include "include/koneksi.inc";
$topic=$_GET['topik'];
$query = $dbc->prepare("SELECT * FROM topic WHERE topic_id = :topic");
$query->bindvalue(":topic", $topic);
$query->execute();
$topic=$query->fetch();
include "view/topik.inc";