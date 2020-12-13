<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
	<?php include "navbar.inc"; ?>
	<div class="content">
		<h1>Dashboard</h1>
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