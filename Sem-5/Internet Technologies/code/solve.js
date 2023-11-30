$(function() {
	$( "#btn" ).click(function() {
		var qid = $( "#qid" ).val();
		var ans = $( "#ans" ).val();

		if(!qid && !ans) {
			$.alert("fill up the fields")   
		}
		else {
			var argu = JSON.stringify({qid:qid, ans:ans});

			$.ajax({
				type : "POST",
				url : "solve.php",
				data : {Sending_data:argu},
				success : function(result,status,xhr) {
					$("#pid").html(result)
				},
				error : function (data) {
					console.log(data);
				}
			});
		}
	});

	$( "#show" ).click(function() {
		var ans = $( "#ans" ).val();
		var qid = $( "#qid" ).val();
		var argu = JSON.stringify({qid:qid, ans:ans});

		$.ajax({
			type : "POST",
			url : "solve.php",
			data : {Sending_data1:argu},
			success : function(result,status,xhr) {
				if(result==1) {
					$("#pid1").html("Right Answer")
					$("#pid2").html("")
				}
				else {
					$("#pid1").html("")
					$("#pid2").html("Wrong Answer")
				}
			},

			error : function (data) {
				console.log(data);
			}
		});
	});
});