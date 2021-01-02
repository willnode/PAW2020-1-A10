<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div class="containerbox">
            <h1>Edit Jawaban</h1>
            <form method="POST">
                    <div class="field">
                        <label for="title">Deskripsi</label> <span><?php echo $answerErr ?></span>
                        <textarea name="answer" class="inputan" id="answer" placeholder="Jawaban" cols="30" rows="10"><?php if (isset($_POST['answer'])) {
                                                                                                                                            echo htmlspecialchars($_POST['answer']);
                                                                                                                                        } else {
                                                                                                                                            echo htmlspecialchars($answer['answer']);
                                                                                                                                        } ?></textarea>
                    </div>
                <div><input type="submit" class="logbutton" value="Simpan" name="submit" id="submit"></div>
            </form>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>