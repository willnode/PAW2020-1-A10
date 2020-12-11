<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    	<?php
			$statement = $dbc->query("SELECT * from topic"); foreach ($statement as $data):
		?>
<div>
	<a href = "topik.php?topik=<?=$data['topic_id']?>">
	<?= $data['title'] ?></a>
</div>
		<?php

			endforeach
		?>
    <?php include "footer.inc"; ?>
</body>

</html>