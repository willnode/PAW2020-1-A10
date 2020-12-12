<div class="navbar">
    <div class="left-bar">
        <ol>
            <li><a href="index.php">Index</a></li>
            <li><a href="beranda.php">Dashboard</a></li>
            <?php
            if (!isset($_SESSION)) {
                session_start();
            }
            if (isset($_SESSION['type'])) {
            ?>
                <li><a href="#">Profile</a></li>
                <li><a href="#">Bio</a></li>
            <?php
            }
            ?>
        </ol>
    </div>
    <div class="right-bar">
        <ol>
            <?php
            if (!isset($_SESSION)) {
                session_start();
            }
            if (!isset($_SESSION['type'])) {
            ?>
                <li><a href="login.php">Login</a></li>
                <li><a href="register.php">Register</a></li>
            <?php
            } else {
                echo "<li><a href=\"logout.php\">Logout</a></li>";
            }
            ?>
        </ol>
    </div>
</div>