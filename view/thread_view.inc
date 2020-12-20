<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div class="regisbox">
            <h1><?= $thread['title'] ?></h1>
            <a href="topik.php?topik=<?= $thread['topic_id'] ?>">Kembali</a>
            <div class="chat">
                <div class="bio">
                    <a href="profile.php?id=<?= $thread['user_id'] ?>"><?= $thread['name'] ?></a>
                </div>
                <div class="content">
                    <?= $thread['question'] ?>
                    <div class="time"><?= $thread['time'] ?></div>
                    <?php if ($thread['user_id'] == $_SESSION['id']) : ?>
                        <a href="thread_edit.php?thread_id=<?= $thread['thread_id'] ?>">Edit</a>
                    <?php endif ?>
                </div>
            </div>
            <hr>
            <?php if (!$answers) : ?>
                <p class="center"><i>Jawaban sedang kosong</i></p>
            <?php endif ?>
            <?php foreach ($answers as $answer) : ?>
                <div class="chat">
                    <div class="bio">
                        <a href="profile.php?id=<?= $answer['user_id'] ?>"><?= $answer['name'] ?></a>
                    </div>
                    <div class="content">
                        <?= $answer['answer'] ?>
                        <div class="time"><?= $answer['time'] ?></div>
                        <?php if ($answer['user_id'] == $_SESSION['id']) : ?>
                            <a href="thread_edit.php?answer_id=<?= $answer['answer_id'] ?>">Edit</a>
                        <?php endif ?>
                    </div>
                </div>
            <?php endforeach ?>
            <hr>
            <form method="post">
                <label for="answer">Jawaban Anda:</label>
                <textarea name="answer" id="answer" class="inputan" rows="10"></textarea>
                <input type="submit" value="Posting Jawaban">
            </form>
        </div>

    </div>
    <?php include "footer.inc"; ?>
</body>

</html>