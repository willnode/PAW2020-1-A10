<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div class="containerbox">
            <h1>Diskusi Baru</h1>
            <form method="POST">
                <div class="field">
                    <label for="title">Judul</label> <span><?php echo $titleErr ?></span>
                    <input name="title" id="title" value="<?php if (isset($_POST['title'])) {
                                                                echo htmlspecialchars($_POST['title']);
                                                            } else {
                                                                echo htmlspecialchars($thread['title']);
                                                            } ?>" class="inputan" placeholder="Pertanyaan Singkat">
                </div>
                <div class="field">
                    <label for="topic">Topik</label> <span><?php echo $topicErr ?></span>
                    <select name="topic" class="inputan" id="topic">
                        <?php foreach ($topics as $topic) : ?>
                            <option <?php echo $thread['topic_id'] == $topic['topic_id'] ? 'selected' : '' ?> value="<?php echo $topic['topic_id'] ?>"><?php echo $topic['title'] ?></option>
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

                <div><input type="submit" class="logbutton" value="Submit" name="submit" id="submit"></div>
            </form>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>