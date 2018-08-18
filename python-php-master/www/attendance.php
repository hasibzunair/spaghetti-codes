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
     echo $row["firstname"].  "  Face : " . $row["face"]. "  Finger : " . $row["finger"]. " Rfid : " . $row["rfid"]. "   Check In : " . $row["datetime"]. " Check Out :" . $row["datetimeend"].

  "<br>";
    }

} else {
   echo "0 results";
}

$conn->close();
?>



