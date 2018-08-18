<?php

$servername ="localhost";
$username="root";
$password="44455566";
$dbname="ship_database";



$conn = new mysqli($servername, $username, $password, $dbname);

if($conn->connect_error) {
     die("Connection failed" . $conn->connect_error);
}


$sql= "SELECT shipname,level,sensor,datetime  FROM shipLog";
$result=$conn->query($sql);

if($result->num_rows > 0){
    while($row = $result->fetch_assoc()) {
     echo $row["shipname"].  "  Water level : " . $row["level"]. "   Sensor : " . $row["sensor"]. "   Datetime : " . $row["datetime"]. "<br>";
    }

} else {
   echo "0 results";
}

$conn->close();
?>


