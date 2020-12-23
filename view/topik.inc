<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div class="topik-fram">
            <h1><img src="image/topik/<?php echo $topic['topic_id'] ?>.png" alt="<?php echo $topic['topic_id'] ?>"><?php echo $topic['title'] ?></h1>
            <a href="thread.php?topic=<?php echo $topic['topic_id'] ?>">Diskusi Baru</a>
            <?php foreach ($threads as $thread) : ?>
                <a href="thread.php?id=<?php echo $thread['thread_id'] ?>"> <?php echo $thread['title'] ?></a>
        </div>
    <?php endforeach ?>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>