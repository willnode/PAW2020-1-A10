<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Register</title>
</head>

<body>
    <?php
    include "header.inc";
    ?>

    <?php
    $nameErr = $avatarErr = $bioErr = $emailErr = $passwordErr = $confirmErr =  "";
    if (isset($_POST['submit'])) {
        require_once "validate.inc";
        validateName($nameErr, $_POST, "name");
        ValidateEmail($emailErr, $_POST, "email");
        validatePass($passwordErr, $_POST, "password");
        required($bioErr, $_POST, "bio");
        // required($avatarErr, $_POST, "avatar");
        validateConfirm($confirmErr, $_POST, "confirm", "password");
        if ($nameErr == "" && $emailErr == "" && $passwordErr == "" && $confirmErr == "" && $bioErr == "") {
            $dbc = new PDO('mysql:host=localhost;dbname=forum', 'root', '');
            $statement = $dbc->prepare("INSERT INTO user (email, password, nama, bio, avatar, type) VALUES (:email, SHA2(:password, 0), :nama,:bio,:avatar, :type)");
            $statement->bindValue(':email', $_POST['email']);
            $statement->bindValue(':password', $_POST['password']);
            $statement->bindValue(':nama', $_POST['name']);
            $statement->bindValue(":bio", $_POST['bio']);
            $statement->bindValue(":avatar", $_POST['avatar']);
            $statement->bindValue(":type", $_POST['type']);
            $statement->execute();
            header("location:index.php");
        }
    }
    ?>
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

    <?php
    include "footer.inc";
    ?>
</body>

</html>