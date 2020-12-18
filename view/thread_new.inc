<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div class="regisbox">
            <h1>Diskusi Baru</h1>
            <form method="POST">
                <div class="field">
                    <label for="title">Judul</label> <span><?php echo $titleErr ?></span>
                    <input name="title" class="inputan" placeholder="Pertanyaan Singkat">
                </div>
                <div class="field">
                    <label for="topic">Topik</label> <span><?php echo $topicErr ?></span>
                    <select name="topic" class="inputan">
                        <?php foreach ($topics as $titem) : ?>
                            <option <?= ($_GET['topic'] ?? '') == $titem['topic_id'] ? 'selected' : '' ?> value="<?= $titem['topic_id'] ?>"><?= $titem['title'] ?></option>
                        <?php endforeach ?>
                    </select>
                </div>
                <div class="field">
                    <label for="title">Deskripsi</label> <span><?php echo $questionErr ?></span>
                    <textarea name="question" class="inputan" id="question" placeholder="Penjelasan Panjang" cols="30" rows="10"></textarea>
                </div>
                <div><input type="submit" class="logbutton" value="Submit" name="submit" id="submit"></div>
            </form>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>