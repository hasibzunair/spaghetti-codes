<?php

$servername ="localhost";
$username="root";
$password="44455566";
$dbname="val_database";



$conn = new mysqli($servername, $username, $password, $dbname);

if($conn->connect_error) {
     die("Connection failed" . $conn->connect_error);
}


$sql= "SELECT datetime,value FROM valLog";
$result=$conn->query($sql);

if($result->num_rows > 0){
    while($row = $result->fetch_assoc()) {
     echo "Datatetime : " . $row["datetime"]. " Value : " . $row["value"]."<br>";
    }

} else {
   echo "0 results";
}

$conn->close();
?>

