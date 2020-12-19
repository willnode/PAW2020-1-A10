<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
    	<div class ="topik-fram">
    		<h1><img src="image/topik/<?= $topic ['topic_id']?>.png"></h1>
       		<h1><?= $topic ['title'] ?></h1>
        	<a href="thread.php?topic=<?= $topic ['topic_id'] ?>">Diskusi Baru</a>
         	<?php foreach ($threads as $thread) : ?>
            <a href ="thread.php?id=<?=$thread['thread_id'] ?>">  <?= $thread ['title'] ?></a></div>
         	<?php endforeach ?>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>