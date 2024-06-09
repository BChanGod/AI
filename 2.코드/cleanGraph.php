<?php
	$conn = mysqli_connect("localhost", "iot", "pwiot");
#	mysqli_set_charset($conn, "UTF-8");
	mysqli_select_db($conn, "Gym");
	$query = "select name, date, time, temp, humi, dcf_index from clean ";
	$result = mysqli_query($conn, $query);

	$data = array(array('KJH_ARD','temp','humi','dcf_index'));

	if($result)
	{
		while($row = mysqli_fetch_array($result))
		{
			array_push($data, array($row['date']."\n".$row['time'], intval($row['temp']),intval($row['humi']) ,intval($row['dcf_index'])));
		}
	}

	$options = array(
			'title' => 'Air Condition',
			'width' => 1000, 'height' => 400,
			'curveType' => 'function'
			);

?>

<script src="//www.google.com/jsapi"></script>
<script>
var data = <?=json_encode($data) ?>;
var options = <?= json_encode($options) ?>;

google.load('visualization', '1.0', {'packages':['corechart']});

google.setOnLoadCallback(function() {
	var chart = new google.visualization.LineChart(document.querySelector('#chart_div'));
	chart.draw(google.visualization.arrayToDataTable(data), options);
	});
	</script>
<div id="chart_div"></div>
