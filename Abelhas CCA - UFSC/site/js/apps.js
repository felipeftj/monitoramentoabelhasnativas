$(document).ready(function () {
    $("#tabela").DataTable({
        "order": [[0, "desc"]]
    });

    $("#botao").click(function () {
        var t1 = "24.3";
        var h1 = "81.1";

        var t2 = "23.0";
        var h2 = "82.1";

        var t3 = "24.1";
        var h3 = "78.2";

        var t4 = "25.7";
        var h4 = "81.1";

        var t5 = "24.6";
        var h5 = "75.1";

        var t6 = "22.4";
        var h6 = "83.2";

        $.post('php/post.php',
			    { t1: t1, h1: h1,  t2: t2, h2: h2,  t3: t3, h3: h3,  t4: t4, h4: h4, t5: t5, h5: h5,  t6: t6, h6: h6 },			    
			    function (resposta) {
			        if (resposta != false) {
			            //$("#status").html(resposta);
			        }
			        else {
			            //$("#status").html("<div> ... </div>");
			            location.reload();
			        }
			    });
    });

});