<?php
    $GLOBALS['hotsaddr']="localhost";
    $GLOBALS['usernm']="shubham";
    $GLOBALS['userpasswordstr']="shubham";
    $GLOBALS['dbnm']="web";

    if(isset($_POST['Sending_data'] )) {
        $parameters = json_decode($_POST['Sending_data']);
        $qid = $parameters->qid;
        $ans = $parameters->ans;

        if(empty($qid))
            $temp = array('outmsg'=>'fill up all the fields ..' );
        else {
            try {
                $conn = mysqli_connect($GLOBALS['hotsaddr'],$GLOBALS['usernm'],$GLOBALS['userpasswordstr'],'web');
                if($conn) {
                    $query = "select *from mcq where sno = "."$qid";
                    $re = mysqli_query($conn,$query);
                    $result = mysqli_fetch_assoc($re);
                    $temp = "Question : ".$result["Questions"]."<br>"."<ol>"."<li>".$result["op1"]."</li>"."<li>".$result["op2"]."</li>"."<li>".$result["op3"]."</li></ol>";
                }
                else {
                    $temp = array('outmsg'=>'connection error ..' );
                }
            }
            catch(Exception $e) {

            }
        }
        echo ( $temp );
    }

    if(isset($_POST['Sending_data1'] )) {
        $parameters = json_decode($_POST['Sending_data1']);
        $ans = $parameters->ans;
        $qid = $parameters->qid;

        if(empty($ans))
            $temp= array('outmsg'=>'fill up all the fields ..' );
        else {
            $conn = mysqli_connect($GLOBALS['hotsaddr'],$GLOBALS['usernm'],$GLOBALS['userpasswordstr'],'web');
            if($conn) {
                $query = "select correct from mcq where sno = "."$qid";
                $re = mysqli_query($conn,$query);
                $result = mysqli_fetch_assoc($re);
            }
            if($ans==$result["correct"])
                echo 1;
            else
                echo 0;
        }
    }
?>