<?php
session_start();
if(!isset($_SESSION['success'])){
    header('location: index.php');
    die();
}




?>



<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Table</title>
	<link rel="stylesheet" href="style.css">
</head>
<body>
    <!--................. Begain ......	-->
	<h1>Table</h1>
	<table>
		<tr>
			<th>Name</th>
			<th>Email</th>
		</tr>
		<tr>
			<td>Salman</td>
			<td>salman.auvi@gmail.com</td>
		</tr>

	</table>
	<!--............. you can delete up to this ........-->
</body>
</html>
