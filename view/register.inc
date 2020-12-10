<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>

    <div class="content">
        <h1>Register</h1>
        <div class="form">
            <form action="register.php" method="POST" class="login">
                <fieldset>
                    <legend>Register</legend>
                    <div class="field">
                        <label for="name">Name</label>
                        <input type="text" name="name" id="name" placeholder="Name" value="<?php if (isset($_POST['name'])) echo htmlspecialchars($_POST['name']) ?>">
                    </div>
                    <span><?php echo $nameErr ?></span>
                    <div class="field">
                        <label for="email">Email</label>
                        <input type="text" name="email" id="email" placeholder="example@email.com" value="<?php if (isset($_POST['email'])) echo htmlspecialchars($_POST['email']) ?>">
                    </div>
                    <span><?php echo $emailErr ?></span>
                    <div class="field">
                        <label for="password">Password</label>
                        <input type="password" id="password" name="password" placeholder="Password" value="<?php if (isset($_POST['password'])) echo htmlspecialchars($_POST['password']) ?>">
                    </div>
                    <span><?php echo $passwordErr ?></span>
                    <div class="field">
                        <label for="confirm">Confirm Passwod</label>
                        <input type="password" name="confirm" id="confirm" placeholder="Password" value="<?php if (isset($_POST['confirm'])) echo htmlspecialchars($_POST['confirm']) ?>">
                    </div>
                    <span><?php echo $confirmErr ?></span>
                    <div class="field">
                        <label for="bio">Bio</label>
                        <input type="text" name="bio" id="bio" placeholder="Bio" value="<?php if (isset($_POST['bio'])) echo htmlspecialchars($_POST['bio']) ?>">
                    </div>
                    <span><?php echo $bioErr ?></span>
                    <div class="field">
                        <label for="type">Type</label>
                        <select name="type" id="type">
                            <option value="client">Client</option>
                            <option value="expert">Expert</option>
                        </select>
                    </div>
                    <div class="field">
                        <label for="avatar">Avatar</label>
                        <input type="file" name="avatar" id="avatar">
                    </div>
                    <span><?php echo $avatarErr ?></span>
                    <div class="field">
                        <label for="submit">&nbsp;</label>
                        <input type="submit" value="submit" name="submit" id="submit">
                    </div>
                </fieldset>
            </form>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>