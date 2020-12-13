<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>

    <div class="content">
        <div class="loginbox">
            <h1>Login</h1>
            <span id="log-err"><?php echo $error ?></span>
            <div class="form">
                <form action="login.php" method="POST" class="login">
                    <div class="field">
                        <label for="email">Email</label><span><?php echo $emailErr ?></span>
                        <input type="text" class="inputan" name="email" id="email" placeholder="email" value="<?php if (isset($_POST['email'])) echo htmlspecialchars($_POST['email']) ?>">
                    </div>
                    <div class="field">
                        <label for="password">Password</label><span><?php echo $passErr ?></span>
                        <input type="password" class="inputan" id="password" name="password" placeholder="password" value="<?php if (isset($_POST['password'])) echo htmlspecialchars($_POST['password']) ?>">
                    </div>
                    <div class="field">
                        <label for="login">&nbsp;</label>
                        <input type="submit" class="logbutton" value="Login" name="login" id="login">
                    </div>
                </form>
            </div>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>