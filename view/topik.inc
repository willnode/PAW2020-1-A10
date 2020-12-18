<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <h1><?= $topic ['title'] ?></h1>
        <a href="thread.php?topic=<?= $topic ['topic_id'] ?>">Diskusi Baru</a>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>