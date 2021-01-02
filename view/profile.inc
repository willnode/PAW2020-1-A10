<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content profile-page">
        <div class="containerbox">
            <?php
            //query untuk mengambil data user
            $query = $dbc->prepare("SELECT * FROM user WHERE user_id=:id");
            $query->bindValue(":id", $_GET['id']);
            $query->execute();
            $result = $query->fetch(PDO::FETCH_ASSOC);
            ?>
            <h1 class="center-text">Profile</h1>
            <div class="left-text">
                <img class="pp" src="<?php echo "image/profile/" . $result['avatar'] ?>" alt="profil">
                <div>
                    <h2><?php echo htmlspecialchars($result['name']); ?></h2>
                    <p><?php echo htmlspecialchars($result['bio']); ?></p>
                </div>
            </div>
            <div class="right-text">
                <h3>Daftar Thread Terkini</h3>
                <ol>
                    <?php
                    //mengecek apakah tipe user adalah expert
                    if ($result['type'] == "expert") {
                        //query untuk thread list yang terdapat reply dari user expert
                        $query = $dbc->prepare("SELECT thread.thread_id,thread.title,answer.time as time FROM answer,thread,topic WHERE answer.thread_id=thread.thread_id AND topic.topic_id=thread.topic_id AND answer.user_id=:id GROUP BY thread_id ORDER BY time DESC");
                        $query->bindValue(":id", $_GET['id']);
                        $query->execute();
                    }
                    //mengecek apakah tipe user client
                    else if ($result['type'] == "client") {
                        //query untuk thread list yang pernah di buat user client
                        $query = $dbc->prepare("SELECT thread_id,thread.title,time FROM thread,topic WHERE topic.topic_id=thread.topic_id AND thread.user_id=:id GROUP BY thread_id ORDER BY time DESC");
                        $query->bindValue(":id", $_GET['id']);
                        $query->execute();
                    }
                    ?>
                    <?php
                    //menampilkan hasil query
                    foreach ($query as $row) {
                    ?>
                        <li><a href="thread.php?id=<?php echo $row['thread_id']; ?>"><?php echo $row['title']; ?></a></li>
                    <?php
                    }
                    ?>
                </ol>
            </div>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>