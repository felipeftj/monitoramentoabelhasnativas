<?php
    require_once("conexao.php");
	     $acao = "SELECT * FROM tb_data ORDER BY id DESC LIMIT 100";
	$resultado = mysqli_query($conexao,$acao);
    while( $coluna=mysqli_fetch_array($resultado,MYSQLI_NUM) ){
		echo "<tr>
				<td>".$coluna[0]."</td>

				<td>".$coluna[1]."</td> <td>".$coluna[2]."</td>
				<td>".$coluna[3]."</td> <td>".$coluna[4]."</td>
				<td>".$coluna[5]."</td> <td>".$coluna[6]."</td>
				<td>".$coluna[7]."</td> <td>".$coluna[8]."</td>
				<td>".$coluna[9]."</td> <td>".$coluna[10]."</td>
				<td>".$coluna[11]."</td><td>".$coluna[12]."</td>
				<td>".$coluna[13]."</td><td>".$coluna[14]."</td>
			</tr>";
    }
?>