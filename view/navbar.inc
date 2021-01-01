<div class="navbar">
    <div class="left-bar">
        <ol>
            <li><a href="index.php">Index</a></li>
            <li><a href="beranda.php">Dashboard</a></li>
        </ol>
    </div>
    <div class="right-bar">
        <?php
        if (!isset($_SESSION)) {
            session_start();
        }
        //cek session aktif
        if (!isset($_SESSION['email'])) {
        ?>
            <ol>
                <li><a href="login.php">Login</a></li>
                <li><a href="register.php">Register</a></li>
            </ol>
        <?php
        } else {
        ?>
            <div class="dropdown">
                <button class="dropbtn"><?php echo $_SESSION['name'] ?></button>
                <div class="dropdown-content">
                    <a href="profile.php?id=<?php echo $_SESSION['id']; ?>">Lihat Profil</a>
                    <a href="edit_profile.php">Edit Profil</a>
                    <a href="change_password.php">Ganti Password</a>
                    <a href="logout.php">Logout</a>
                </div>
            </div>
        <?php
        }
        ?>
    </div>
</div>