<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>

    <div class="content">
        <h1>Login</h1>
        <div class="form">
            <form action="login.php" method="POST" class="login">
                <fieldset>
                    <legend>Login</legend>
                    <div class="field">
                        <label for="email">Email</label>
                        <input type="text" name="email" id="email" placeholder="Email">
                    </div>
                    <div class="field">
                        <label for="password">Password</label>
                        <input type="password" id="password" name="password" placeholder="Password">
                    </div>
                    <div class="field">
                        <label for="login">&nbsp;</label>
                        <input type="submit" value="Login" name="login" id="login">
                    </div>
                </fieldset>
            </form>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>