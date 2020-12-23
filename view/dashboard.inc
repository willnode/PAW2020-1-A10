<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
	<?php include "navbar.inc"; ?>
	<div class="content">
		<div class="regisbox">
			<h1 class="center-text">Dashboard</h1>
			<?php
			$statement = $dbc->query("SELECT * from topic");
			foreach ($statement as $data) :
			?>
				<div class="topik-item">
					<img src="image/topik/<?php echo $data['topic_id'] ?>.png" alt="<?php echo $data['topic_id'] ?> ?>">
					<div><a href="topik.php?topik=<?php echo $data['topic_id'] ?>">
							<?php echo $data['title'] ?></a>
						<p><?php echo $data['description'] ?></p>
					</div>
				</div>
			<?php
			endforeach
			?>
		</div>
	</div>
	<?php include "footer.inc"; ?>
</body>

</html>