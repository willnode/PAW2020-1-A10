<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <h1 class="center-text">Profile</h1>
        <?php
        $query = $dbc->prepare("SELECT avatar FROM user WHERE email=:email");
        $query->bindValue(":email", $_SESSION['email']);
        $query->execute();
        $result = $query->fetchAll(PDO::FETCH_COLUMN, 0);
        ?>
        <div class="center">
            <?php
            $image = "image/profile/" . $result[0];
            ?>
            <img class="pp" src="<?php echo $image ?>" alt="<?php echo $result[0]; ?>">
        </div>
        <div class="center-text">
            <ol>
                <li>Email : <?php echo $_SESSION['email']; ?></li>
                <li>Nama : <?php echo $_SESSION['name']; ?></li>
                <li>Bio : <?php echo $_SESSION['bio']; ?></li>
            </ol>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>