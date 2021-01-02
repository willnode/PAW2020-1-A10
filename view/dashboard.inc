<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
	<?php include "navbar.inc"; ?>
	<div class="content">
		<div class="containerbox">
			<h1 class="center-text">Dashboard</h1>
			<?php
			//mengambil seluruh topic yang ada
			$statement = $dbc->query("SELECT * from topic");
			foreach ($statement as $data) :
			?>
				<a class="topik-item" href="topik.php?topik=<?php echo $data['topic_id'] ?>">
					<img src="image/topik/<?php echo $data['topic_id'] ?>.png" alt="<?php echo $data['topic_id'] ?> ?>">
					<div>
						<h4><?php echo $data['title'] ?></h4>
						<p><?php echo $data['description'] ?></p>
					</div>
				</a>
			<?php
			endforeach
			?>

			<a class="topik-item arsip" href="profile.php?id=<?php echo $_SESSION['id'] ?>">
				<div>
					Lihat Arsip Diskusi Anda
				</div>
			</a>
		</div>
	</div>
	<?php include "footer.inc"; ?>
</body>

</html>