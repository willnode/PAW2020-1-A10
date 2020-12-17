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
        if (!isset($_SESSION['type'])) {
        ?>
            <ol>
                <li><a href="login.php">Login</a></li>
                <li><a href="register.php">Register</a></li>
            </ol>
        <?php
        } else {
        ?>
            <div class="dropdown">
                <button class="dropbtn"><?php echo $_SESSION['nama'] ?></button>
                <div class="dropdown-content">
                    <a href="profile.php">Profile</a>
                    <a href="edit_profile.php?id=<?php echo $_SESSION['id']; ?>">Edit Profile</a>
                    <a href="change_password.php?id=<?php echo $_SESSION['id']; ?>">Change Password</a>
                    <a href="logout.php">Logout</a>
                </div>
            </div>
        <?php
        }
        ?>
    </div>
</div>