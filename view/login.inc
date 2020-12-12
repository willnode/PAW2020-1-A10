<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>

    <div class="content">
        <div class="loginbox">
        <h1>Login</h1>
        <div class="form">
            <form action="login.php" method="POST" class="login">
                <div class="field">
                    <label for="email">Email</label>
                    <input type="text" class="inputan" name="email" id="email">
                </div>
                <div class="field">
                    <label for="password">Password</label>
                    <input type="password" class="inputan" id="password" name="password">
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