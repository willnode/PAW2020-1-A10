<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <h1 class="center-text">Profile</h1>
        <?php
        $query = $dbc->prepare("SELECT * FROM user WHERE user_id=:id");
        $query->bindValue(":id", $_GET['id']);
        $query->execute();
        $result = $query->fetchAll(PDO::FETCH_ASSOC);
        ?>
        <div class="center">
            <?php
            $image = "image/profile/" . $result[0]['avatar'];
            ?>
            <img class="pp" src="<?php echo $image ?>" alt="<?php echo $result[0]['avatar']; ?>">
        </div>
        <div class="center-text">
            <ol>
                <li>Email : <?php echo $result[0]['email']; ?></li>
                <li>Nama : <?php echo $result[0]['name']; ?></li>
                <li>Bio : <?php echo $result[0]['bio']; ?></li>
            </ol>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>