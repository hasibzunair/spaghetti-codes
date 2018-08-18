<!DOCTYPE html>
<html>
<head>
<style>


body {
background-color: DodgerBlue;
}

h1 {
color: white;
text-align: center;
}

p.solid {border-style: solid;}

</style>
</head>
<body>


<p><a href="logout.php">Logout</a></p>

<h1>EEE499 ATTENDANCE SYSTEM </h1>

<h1>
<table width="100%" border="5" bordercolor=BLUE >
 <thead><tr>
   <td>NAME</td>
   <td>FACE</td>
   <td>FINGER</td>
   <td>RFID</td>
   <td>CHECKIN</td>
   <td>CHECKOUT</td>
   </tr>
   </thead>
   <tbody>
</h1>

<?php


$servername ="localhost";
$username="root";
$password="44455566";
$dbname="attendance_database";



$conn = new mysqli($servername, $username, $password, $dbname);

if($conn->connect_error) {
     die("Connection failed" . $conn->connect_error);
}


$sql= "SELECT firstname,face,finger,rfid,datetime,datetimeend FROM attendanceLog";
$result=$conn->query($sql);

if($result->num_rows > 0){
    while($row = $result->fetch_assoc()) {
     echo
"<tr>
 <td>{$row["firstname"]}</td>
<td>{$row["face"]}</td>
<td>{$row["finger"]}</td>
<td>{$row["rfid"]}</td>
<td>{$row["datetime"]}</td>
<td>{$row["datetimeend"]}</td>

</tr>\n";
 }

} else {
   echo "0 results";
}

$conn->close();
?>



</body>
</html>
