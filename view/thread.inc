<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <?php if (isset($thread)) : ?>
            <!-- Thread sudah ada -->
            <h1><?= $topic['title'] ?></h1>
        <?php else : ?>
            <!-- Thread baru -->
            <h1>Diskusi Baru</h1>
            <form method="POST">
                <div><input name="title"></div>
                <div><textarea name="question" id="question" cols="30" rows="10"></textarea></div>
                <div><input type="submit" value="Kirim"></div>
            </form>

        <?php endif ?>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>