<?php

$username="root";
$password="44455566";
$database="val_database";

mysql_connect(localhost,$username,$password);
@mysql_select_db($database) or die( "Unable to select database");

$query="SELECT * FROM valLog";
$result=mysql_query($query);

$num=mysql_numrows($result);
mysql_close();
$valValues = array();

$i=0;
while ($i < $num)
{
        $dateAndVal = array();
        $datetime = mysql_result($result,$i,"datetime");
        $val = mysql_result($result,$i,"value");

        $dateAndVal["Date"] = $datetime;
        $dateAndVal["Value"] = $val;

        $valValues[$i]=$dateAndVal;
        $i++;
}
echo json_encode($valValues);

?>

