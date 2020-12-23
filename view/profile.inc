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
        $result = $query->fetch(PDO::FETCH_ASSOC);
        ?>
        <div class="center">
            <?php
            $image = "image/profile/" . $result['avatar'];
            ?>
            <img class="pp" src="<?php echo $image ?>" alt="<?php echo $result['avatar']; ?>">
        </div>
        <div class="left-text">
            <ol>
                <li>Email : <?php echo $result['email']; ?></li>
                <li>Nama : <?php echo $result['name']; ?></li>
                <li>Bio : <?php echo $result['bio']; ?></li>
            </ol>
        </div>
        <div class="right-text">
            <ol>
                <?php
                //cek tipe user
                if ($_SESSION['id'] == $_GET['id']) {
                    $query = $dbc->prepare("SELECT thread.thread_id,thread.title,answer.time as time FROM answer,thread,topic WHERE answer.thread_id=thread.thread_id AND topic.topic_id=thread.topic_id AND answer.user_id=:id GROUP BY thread_id");
                    $query->bindValue(":id", $_GET['id']);
                    $query->execute();
                } else {
                    $query = $dbc->prepare("SELECT thread_id,thread.title,time FROM thread,topic WHERE topic.topic_id=thread.topic_id AND thread.user_id=:id GROUP BY thread_id");
                    $query->bindValue(":id", $_GET['id']);
                    $query->execute();
                }
                ?>
                <?php
                //menampilkan hasil query
                foreach ($query as $row) {
                ?>
                    <li><a href="thread.php?id=<?php echo $row['thread_id']; ?>"><?php echo $row['title'] . " " . $row['time']; ?></a></li>
                <?php
                }
                ?>
            </ol>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>