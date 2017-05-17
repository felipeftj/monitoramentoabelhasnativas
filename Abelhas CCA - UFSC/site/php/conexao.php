<?php
	$rede 		= "mysql.hostinger.com.br";
	$usuario 	= "u629018256_root";
	$senha 		= "16021987q";
	$banco_de_dados = "u629018256_db";
	$conexao        = mysqli_connect($rede, $usuario, $senha, $banco_de_dados);

	if (!$conexao) {
         	die('Connect Error: ' . mysqli_connect_error());
	}
?>