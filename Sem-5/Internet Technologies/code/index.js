$(function() {
	var carop = "";
	$(".ops").click(function() {
		carop = $(this).prop('value');
	});

	$( "#sub" ).click(function() {
		var qun = $( "#qun" ).val();
		var op1 = $( "#op1" ).val();
		var op2 = $( "#op2" ).val();
		var op3 = $( "#op3" ).val();
		if(!qun && !op1 && !op2 && !op3) {
			$.alert("fill up the fields");
		}
		else {
			var argu=JSON.stringify({qun:qun, op1:op1, op2:op2, op3:op3, cops:carop});

			$.ajax({
				url : "testbackend.php",
				dataType : "json",
				data : {Sending_data:argu },
				method : "post",
				success : function(data) {
					jQuery("input[name='ops']").each(function(i){
						jQuery(this).attr('disabled','disabled')
					})
					alert(data.outmsg);
				},
				error : function (data) {
					console.log(data);
				}
			});
		}
	});
});