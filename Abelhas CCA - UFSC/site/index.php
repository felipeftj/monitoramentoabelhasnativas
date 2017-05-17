<!DOCTYPE html>
<html lang="pt-BR">
	<head>
		<meta charset="UTF-8">
		<title>dB: abelhasCCA</title>
		<link rel="icon" href="img/icon.png">
		<link type="text/css"	rel="stylesheet"	href="css/estilo.css">
		<link type="text/css"	rel="stylesheet"	href="css/jquery.dataTables.min.css">
	</head>
	<body>
	    <header>
		    <h1>dataBase</h1>
		</header>
		<article>
		    <table id="tabela" class="display" cellspacing="0" width="100%">
			    <thead>
				    <tr class="tituloColuna">
				        <th>Id</th>
				        <th>Data</th>
				        <th>Hora</th>
				        <th>[1]T</th>
				        <th>[1]H</th>
						<th>[2]T</th>
				        <th>[2]H</th>
				        <th>[3]T</th>
				        <th>[3]H</th>
						<th>[4]T</th>
				        <th>[4]H</th>
				        <th>[5]T</th>
				        <th>[5]H</th>
						<th>[6]T</th>
				        <th>[6]H</th>
				    </tr>
			    </thead>
			    <tbody>
				    <?php include("php/select.php"); ?>
			    </tbody>
            </table>
		</article>
        <button id="botao">+</button>
		<script type="text/javascript" src="js/jquery-1.11.3.min.js"></script>
		<script type="text/javascript" src="js/jquery.dataTables.min.js"></script>
		<script type="text/javascript" src="js/apps.js"></script>
	</body>
</html>