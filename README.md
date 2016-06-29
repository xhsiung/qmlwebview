# QmlWebView Project
QmlWebView Project objectives is intergrated  communication for android on the QTs environment.

## Structure 
![image](https://raw.githubusercontent.com/xhsiung/qmlwebview/master/imgs/qmlstruct.png)


## How to Build
```
git clone https://github.com/xhsiung/qmlwebview.git
cd qmlwebview
qmake
make 
```

## Usage

connect server 
```Connect
$.android.connect(successFn,errorFn)
```

disconnect server
```
$.android.disconnect() ;
```

send
```
$.android.send(obj);
```

Sample
```
<html>
<head>

<title>Sample "Hello, World" Application</title>
<script src="js/jquery-1.11.3.js"></script>
<script src="js/jquery.android.min.js"></script>

<script>

$(function(){
        //init connect
        connect();

        //bind listener
        $("#listener").bind("androidEvent", function(e, obj ){
                        $("#message").append("<p>" + obj.data + "</p>");
        });
});

function connect(){
        //connect
        var conn = $.android.connect(function(){
                //connection success
                $('#message').html('success to connect.');
        },
        function(err){
                //connection error
                //err.code , err.reason
                $('#message').html('fail to connect.  err code:' + err.code);
        });
}

function disconnect(){
       $.android.disconnect() ;
}

//send can run
function send(){
          var obj = { name:"alex" , mobile:"0938058318" , data: $("#xdata").val() } ;
          $.android.send(  obj  );
          $("#xdata").val('');
 }

</script>
</head>
<body>
        <div id="listener"> </div>
        <div id="message"> </div>

         <input type="text"  id= "xdata"  placeholder="data"  />
        <input type="button" value="connect" onClick="connect()">
        <input type="button" value="disconnect" onClick="disconnect()">
        <input type="button" value="send" onClick="send()">
</body>
</html>

```

## Current status

Done  work:
* Connect  websocket

## History

* **v1.0.0** : 2016-06-29
