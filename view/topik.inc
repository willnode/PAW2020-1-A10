<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div class="topik-fram">
            <h1><img src="image/topik/<?php echo $topic['topic_id'] ?>.png" alt="<?php echo $topic['topic_id'] ?>"><?php echo $topic['title'] ?></h1>
            <?php if ($_SESSION['type'] == 'client') : ?>
            <a href="thread.php?topic=<?php echo $topic['topic_id'] ?>" class="logbutton">Diskusi Baru</a>
            <?php endif ?>
            <?php foreach ($threads as $thread) : ?>
            <div class="thread-item">
               <a href="thread.php?id=<?php echo $thread['thread_id'] ?>"> <?php echo $thread['title'] ?></a><br>
               <span class="thread-time"><?php echo $thread ["time"] ?></span>
            </div>
    <?php endforeach ?>
    </div>
</div>
    <?php include "footer.inc"; ?>
</body>

</html>