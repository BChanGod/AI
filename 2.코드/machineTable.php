<!DOCTYPE html>
<html>
<head>
	<meta charset = "UTF-8">
	<meta http-equiv = "refresh" content = "30">
	<style type = "text/css">
		.spec{
			text-align:center;
		}
		.con{
			text-align:left;
		}
		</style>
</head>

<body>
	<h1 align = "center">iot Database</h1>
	<div class = "spec">
		# <b>The sensor value description</b>
		<br></br>
	</div>

	<table border = '1' style = "width = 30%" align = "center">
	<tr align = "center">
		<th>ID</th>
		<th>NAME</th>
		<th>DATE</th>
		<th>TIME</th>
		<th>KM</th>
		<th>KCAL</th>
		<th>TOTAL</th>
	</tr>

	<?php
		$conn = mysqli_connect("localhost", "iot", "pwiot");
		mysqli_select_db($conn, "Gym");
		$result = mysqli_query($conn, "select * from machine");
		while($row = mysqli_fetch_array($result))
		{
			echo "<tr align = center>";
			echo '<th>'.$row['id'].'</td>';
			echo '<th>'.$row['name'].'</td>';
			echo '<th>'.$row['date'].'</td>';
			echo '<th>'.$row['time'].'</td>';
			echo '<th>'.$row['km'].'</td>';
			echo '<th>',$row['kcal'].'</td>';
	      	echo '<th>',$row['total'].'</td>';
			echo "</tr>";

		}

		mysqli_close($conn);
	?>
	</table>
</body>
</html>
