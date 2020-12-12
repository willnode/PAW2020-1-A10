<?php
require 'include/adminPermission.inc';
include "include/koneksi.inc";
include "view/dashboard.inc";
?>
<div class="content">
    <?php echo "Email =" . $_SESSION['email']; ?>
    <?php echo "</br>Nama =" . $_SESSION['nama']; ?>
    <?php echo "</br>bio =" . $_SESSION['bio']; ?>
    <?php echo "</br>Type =" . $_SESSION['type']; ?>
</div>