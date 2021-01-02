<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div class="containerbox">
            <h1><?php echo $thread['title'] ?></h1>
            <a class="btn" href="topik.php?topik=<?php echo $thread['topic_id'] ?>">Kembali</a>
            <div class="chat">
                <a class="bio" href="profile.php?id=<?php echo $thread['user_id'] ?>">
                    <img src="image/profile/<?php echo $thread['avatar'] ?>" class="profile" alt="avatar">
                    <div><?php echo $thread['name'] ?></div>
                </a>
                <div class="content">
                    <?php echo $thread['question'] ?>
                    <div class="time"><?php echo $thread['time'] ?></div>
                    <?php if ($thread['user_id'] == $_SESSION['id']) : ?>
                        <a class="btn" href="thread_post.php?id=<?php echo $thread['thread_id'] ?>">Edit</a>
                    <?php endif ?>
                </div>
            </div>
            <hr>
            <?php if (!$answers) : ?>
                <p class="center"><i>Jawaban sedang kosong</i></p>
            <?php endif ?>
            <?php foreach ($answers as $answer) : ?>
                <div class="chat">
                    <a class="bio" title="Lihat Profil" href="profile.php?id=<?php echo $answer['user_id'] ?>">
                        <img src="image/profile/<?php echo $answer['avatar'] ?>" class="profile" alt="<?php echo $answer['avatar'] ?>">
                        <div><?php echo $answer['name'] ?></div>
                    </a>
                    <div class="content">
                        <?php echo $answer['answer'] ?>
                        <div class="time"><?php echo $answer['time'] ?></div>
                        <?php if ($answer['user_id'] == $_SESSION['id']) : ?>
                            <a class="btn" href="edit_answer.php?answer_id=<?php echo $answer['answer_id'] ?>">Edit</a>
                        <?php endif ?>
                    </div>
                </div>
            <?php endforeach ?>
            <hr>
            <?php if ($_SESSION['type'] == 'expert') : ?>
                <form method="post">
                    <label for="answer">Jawaban Anda:</label>
                    <span class="error"><?php echo $answerErr ?? '' ?></span>
                    <textarea name="answer" id="answer" class="inputan" rows="10"></textarea>
                    <input class="btn" type="submit" value="Posting Jawaban">
                </form>
            <?php endif ?>
        </div>

    </div>
    <?php include "footer.inc"; ?>
</body>

</html>