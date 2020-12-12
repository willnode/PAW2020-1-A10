<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>

    <div class="content">
        <div class="regisbox">
        <h1>Register</h1>
        <div class="form">
            <form action="register.php" method="POST" class="login">
                <div class="field">
                    <label for="name">Name</label> <span><?php echo $nameErr ?></span>
                    <input type="text" class="inputan" name="name" id="name" placeholder="Name" value="<?php if (isset($_POST['name'])) echo htmlspecialchars($_POST['name']) ?>">
                </div>
                <div class="field">
                    <label for="email">Email</label><span><?php echo $emailErr ?></span>
                    <input type="text" class="inputan" name="email" id="email" placeholder="example@email.com" value="<?php if (isset($_POST['email'])) echo htmlspecialchars($_POST['email']) ?>">
                </div>
                <div class="field">
                    <label for="password">Password</label> <span><?php echo $passwordErr ?></span>
                    <input type="password" class="inputan" id="password" name="password" placeholder="Password" value="<?php if (isset($_POST['password'])) echo htmlspecialchars($_POST['password']) ?>">
                </div>
                <div class="field">
                    <label for="confirm">Confirm Passwod</label> <span><?php echo $confirmErr ?></span>
                    <input type="password" class="inputan" name="confirm" id="confirm" placeholder="Password" value="<?php if (isset($_POST['confirm'])) echo htmlspecialchars($_POST['confirm']) ?>">
                </div>
                <div class="field">
                    <label for="bio">Bio</label> <span><?php echo $bioErr ?></span>
                    <input type="text" class="inputan" name="bio" id="bio" placeholder="Bio" value="<?php if (isset($_POST['bio'])) echo htmlspecialchars($_POST['bio']) ?>">
                </div>
                <div class="field">
                    <label for="type">Type</label>
                    <select name="type" id="type" class="inputan">
                        <option value="client">Client</option>
                        <option value="expert">Expert</option>
                    </select>
                </div>
                <div class="field">
                    <label for="avatar">Avatar</label> <span><?php echo $avatarErr ?></span>
                    <input type="file" class="ava" name="avatar" id="avatar">
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