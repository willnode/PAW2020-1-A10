<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <h1>Profile</h1>
        <?php echo "Email =" . $_SESSION['email']; ?>
        <?php echo "</br>Nama =" . $_SESSION['nama']; ?>
        <?php echo "</br>bio =" . $_SESSION['bio']; ?>
        <?php echo "</br>Type =" . $_SESSION['type']; ?>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>