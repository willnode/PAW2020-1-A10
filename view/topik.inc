<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div class="topik-fram">
            <h1><img src="image/topik/<?php echo $topic['topic_id'] ?>.png" alt="ikon"><?php echo $topic['title'] ?></h1>
            <?php foreach (array_reverse($threads) as $thread) :
                // Looping per thread (dari terbaru)
            ?>
                <a class="thread-item" href="thread.php?id=<?php echo $thread['thread_id'] ?>">
                    <div>
                        <h4><?php echo $thread['title'] ?></h4>
                        <span class="thread-time"><?php echo $thread["time"] ?></span>
                    </div>
                </a>
            <?php endforeach ?>
            <?php
            if ($_SESSION['type'] == 'client') :
                // Hanya client yang boleh membuka diskusi baru
            ?>
                <a href="thread_post.php?topic=<?php echo $topic['topic_id'] ?>" class="logbutton">Diskusi Baru</a>
            <?php endif ?>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>