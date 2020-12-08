<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Login</title>
</head>

<body>
    <?php
    function checkPassword($email, $password)
    {
        $dbc = new PDO('mysql:host=localhost;dbname=forum', 'root', '');
        $query = $dbc->prepare("SELECT * FROM user WHERE email = :email AND password = SHA2(:password,0)");
        $query->bindvalue(":email", $email);
        $query->bindValue(":password", $password);
        $query->execute();
        return $query->rowCount() > 0;
    }

    if (isset($_POST['login'])) {
        if (checkPassword($_POST["email"], $_POST['password'])) {
            session_start();
            $_SESSION['email'] = $_POST['email'];
            $_SESSION['isAdmin'] = true;
            header("location:beranda.php");
            exit();
        }
    }
    ?>
    <?php
    include "header.inc";
    ?>

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
    <?php
    include "footer.inc";
    ?>
</body>

</html>