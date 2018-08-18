<?php

$servername = "localhost";
$username="root";
$password="44455566";


$conn = new mysqli($servername, $username, $password);

if ($conn-> connect_error) {
  
  die("Failed: " . $conn->connect_error);
}

echo "YAY";

?>
