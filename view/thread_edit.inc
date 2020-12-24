<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div class="regisbox">
            <h1>Edit Diskusi</h1>
            <form method="POST">
                <?php if (isset($thread)) : ?>
                    <div class="field">
                        <label for="title">Judul</label> <span><?php echo $titleErr ?></span>
                        <input name="title" value="<?php if (isset($_POST['title'])) {
                                                        echo htmlspecialchars($_POST['title']);
                                                    } else {
                                                        echo htmlspecialchars($thread['title']);
                                                    } ?>" class="inputan" placeholder="Pertanyaan Singkat">
                    </div>
                    <div class="field">
                        <label for="topic">Topik</label> <span><?php echo $topicErr ?></span>
                        <select name="topic" class="inputan">
                            <?php foreach ($topics as $titem) : ?>
                                <option <?php echo $thread['topic_id'] == $titem['topic_id'] ? 'selected' : '' ?> value="<?php echo $titem['topic_id'] ?>"><?php echo $titem['title'] ?></option>
                            <?php endforeach ?>
                        </select>
                    </div>
                    <div class="field">
                        <label for="question">Deskripsi</label> <span><?php echo $questionErr ?></span>
                        <textarea name="question" class="inputan" id="question" placeholder="Penjelasan Panjang" cols="30" rows="10"><?php if (isset($_POST['question'])) {
                                                                                                                                            echo htmlspecialchars($_POST['question']);
                                                                                                                                        } else {
                                                                                                                                            echo htmlspecialchars($thread['question']);
                                                                                                                                        } ?></textarea>
                    </div>
                <?php elseif (isset($answer)) : ?>
                    <div class="field">
                        <label for="title">Deskripsi</label> <span><?php echo $questionErr ?></span>
                        <textarea name="answer" class="inputan" id="answer" placeholder="Jawaban" cols="30" rows="10"><?php if (isset($_POST['answer'])) {
                                                                                                                                            echo htmlspecialchars($_POST['answer']);
                                                                                                                                        } else {
                                                                                                                                            echo htmlspecialchars($thread['answer']);
                                                                                                                                        } ?></textarea>
                    </div>
                <?php endif ?>
                <div><input type="submit" class="logbutton" value="Simpan" name="submit" id="submit"></div>
            </form>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>