<!DOCTYPE html> <!--menandakan html versi 5 (tipe)-->
<html lang="en"> <!--html : untuk membuat dokumen html, lang : untuk menyatakan bahasa halaman web-->
<?php include "head.inc" ?> <!--menyisipkan halaman head.inc-->

<body>
    <?php include "navbar.inc"; ?> <!--menyisipkan halaman navbar.inc-->
    <?php
    $query = $dbc->prepare("SELECT * FROM user WHERE user_id=:id");
    $query->bindValue(":id", $_SESSION['id']);
    $query->execute();
    $result = $query->fetchAll(PDO::FETCH_ASSOC);
    ?>
    <div class="content">
        <div class="containerbox">
            <h1>Ganti Password</h1>
            <div class="form">
                <!--membuat form pengisian data untuk change password-->
                <form action="change_password.php" method="POST" class="login">
                    <div class="field">
                        <label for="old_password">Password Lama</label> <span><?php echo $oldPassErr ?></span>
                        <input type="password" class="inputan" id="old_password" name="old_password" value="<?php if (isset($_POST['old_password'])) echo htmlspecialchars($_POST['old_password']) ?>">
                        <input type="hidden" name="id" id="id" value="<?php echo $_SESSION['id']; ?>">
                    </div>
                    <div class="field">
                        <label for="new_password">Password Baru</label> <span><?php echo $newPassErr ?></span>
                        <input type="password" class="inputan" name="new_password" id="new_password" value="<?php if (isset($_POST['new_password'])) echo htmlspecialchars($_POST['new_password']) ?>">
                    </div>
                    <div class="field">
                        <label for="confirm">Konfirmasi Password Baru</label> <span><?php echo $confirmPassErr ?></span>
                        <input type="password" class="inputan" name="confirm" id="confirm" value="<?php if (isset($_POST['confirm'])) echo htmlspecialchars($_POST['confirm']) ?>">
                    </div>
                    <div class="field">
                        <input type="submit" class="logbutton" value="Submit" name="submit" id="submit">
                    </div>
                </form>
                <!--form end-->
            </div>
        </div>
    </div>
    <?php include "footer.inc"; ?> <!--menysipkan file footer.inc-->
</body>

</html>