<?php
require 'include/adminPermission.inc';
include "include/koneksi.inc";
if (isset($_GET['thread']))
{
    $thread=$_GET['thread'];
    $query = $dbc->prepare("SELECT * FROM thread WHERE thread_id = :thread");
    $query->bindvalue(":thread", $thread);
    $query->execute();
    $thread=$query->fetch();
}
include "view/thread.inc";