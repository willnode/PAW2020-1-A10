<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <?php
    $query = $dbc->prepare("SELECT * FROM user WHERE user_id=:id");
    $query->bindValue(":id", $_GET['id']);
    $query->execute();
    $result = $query->fetchAll(PDO::FETCH_ASSOC);
    ?>
    <div class="content">
        <div class="regisbox">
            <h1>Change Password</h1>
            <div class="form">
                <form action="change_password.php" method="POST" class="login">
                    <div class="field">
                        <label for="old_password">Old Password</label> <span><?php echo $oldPassErr ?></span>
                        <input type="password" class="inputan" id="old_password" name="old_password" placeholder="Old Password" value="<?php if (isset($_POST['old_password'])) echo htmlspecialchars($_POST['old_password']) ?>">
                        <input type="hidden" name="id" id="id" value="<?php echo $_SESSION['id']; ?>">
                    </div>
                    <div class="field">
                        <label for="new_password">New Passwod</label> <span><?php echo $newPassErr ?></span>
                        <input type="password" class="inputan" name="new_password" id="new_password" placeholder="New Password" value="<?php if (isset($_POST['new_password'])) echo htmlspecialchars($_POST['new_password']) ?>">
                    </div>
                    <div class="field">
                        <label for="confirm">Confirm Passwod</label> <span><?php echo $confirmPassErr ?></span>
                        <input type="password" class="inputan" name="confirm" id="confirm" placeholder="Confirm Password" value="<?php if (isset($_POST['confirm'])) echo htmlspecialchars($_POST['confirm']) ?>">
                    </div>
                    <div class="field">
                        <label for="submit">&nbsp;</label>
                        <input type="submit" class="logbutton" value="Submit" name="submit" id="submit">
                    </div>
                </form>
            </div>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>