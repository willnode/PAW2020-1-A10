<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
	<?php include "navbar.inc"; ?>
	<div class="content">
		<?php echo "Email =" . $_SESSION['email']; ?>
		<?php echo "</br>Nama =" . $_SESSION['nama']; ?>
		<?php echo "</br>bio =" . $_SESSION['bio']; ?>
		<?php echo "</br>Type =" . $_SESSION['type']; ?>
		<?php
		$statement = $dbc->query("SELECT * from topic");
		foreach ($statement as $data) :
		?>
			<div>
				<a href="topik.php?topik=<?= $data['topic_id'] ?>">
					<?= $data['title'] ?></a>
			</div>
		<?php

		endforeach
		?>
	</div>
	<?php include "footer.inc"; ?>
</body>

</html>