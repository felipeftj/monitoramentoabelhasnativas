<?php
	date_default_timezone_set("America/Sao_Paulo");
    require_once("conexao.php");

         $t1 = 0;   $h1 = 0;
         $t2 = 0;   $h2 = 0;
         $t3 = 0;   $h3 = 0;
         $t4 = 0;   $h4 = 0;
         $t5 = 0;   $h5 = 0;
         $t6 = 0;   $h6 = 0;

        if( !empty($_POST["t1"])   ) { $t1    = $_POST["t1"];    }
        if( !empty($_POST["h1"])   ) { $h1    = $_POST["h1"];    }

        if( !empty($_POST["t2"])   ) { $t2    = $_POST["t2"];    }
        if( !empty($_POST["h2"])   ) { $h2    = $_POST["h2"];    }

        if( !empty($_POST["t3"])   ) { $t3    = $_POST["t3"];    }
        if( !empty($_POST["h3"])   ) { $h3    = $_POST["h3"];    }

        if( !empty($_POST["t4"])   ) { $t4    = $_POST["t4"];    }
        if( !empty($_POST["h4"])   ) { $h4    = $_POST["h4"];    }

        if( !empty($_POST["t5"])   ) { $t5    = $_POST["t5"];    }
        if( !empty($_POST["h5"])   ) { $h5    = $_POST["h5"];    }

        if( !empty($_POST["t6"])   ) { $t6    = $_POST["t6"];    }
        if( !empty($_POST["h6"])   ) { $h6    = $_POST["h6"];    }

       $data = date("j/m/Y");
       $hora = date('H:i:s');
       $acao = "INSERT INTO tb_data
        (data,hora, t1,h1, t2,h2, t3,h3, t4,h4, t5,h5, t6,h6) VALUES
        ('$data','$hora' ,'$t1','$h1' ,'$t2','$h2' ,'$t3','$h3' ,'$t4','$h4' ,'$t5','$h5' ,'$t6','$h6' )";

    mysqli_query($conexao,$acao);
?>