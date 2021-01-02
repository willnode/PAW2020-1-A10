<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <?php
    // mengambil informasi user sesuai dengan session id
    $query = $dbc->prepare("SELECT * FROM user WHERE user_id=:id");
    $query->bindValue(":id", $_SESSION['id']);
    $query->execute();
    $result = $query->fetch(PDO::FETCH_ASSOC);
    ?>
    <div class="content">
        <div class="containerbox">
            <h1>Edit Profil</h1>
            <div class="form">
                <!-- form untuk mengedit informasi profile -->
                <form action="edit_profile.php" method="POST" class="login" enctype="multipart/form-data">
                    <div class="field">
                        <label for="name">Nama</label> <span><?php echo $nameErr ?></span>
                        <input type="text" class="inputan" name="name" id="name" placeholder="Nama" value="<?php if (isset($_POST['name'])) {
                                                                                                                echo htmlspecialchars($_POST['name']);
                                                                                                            } else {
                                                                                                                echo htmlspecialchars($result['name']);
                                                                                                            } ?>">
                        <input type="hidden" name="id" id="id" value="<?php echo $_SESSION['id']; ?>">
                    </div>
                    <div class="field">
                        <label for="bio">Bio</label> <span><?php echo $bioErr ?></span>
                        <input type="text" class="inputan" name="bio" id="bio" placeholder="Bio Singkat" value="<?php if (isset($_POST['bio'])) {
                                                                                                                    echo htmlspecialchars($_POST['bio']);
                                                                                                                } else {
                                                                                                                    echo htmlspecialchars($result['bio']);
                                                                                                                } ?>">
                    </div>
                    <div class="field">
                        <label for="avatar">Avatar</label> <span><?php echo $avatarErr ?></span>
                        <input type="file" class="ava" name="avatar" id="avatar">
                        <div class="field">
                            <label for="submit">&nbsp;</label>
                            <input type="submit" class="logbutton" value="Submit" name="submit" id="submit">
                        </div>
                    </div>
                </form>
            </div>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>