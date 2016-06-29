import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Window 2.0

import QtWebSockets 1.0
import QtWebView 1.1

ApplicationWindow {
    visible: true
    title: webView.title

    WebSocketServer {
        id: server
        listen: true
        onClientConnected: {
            webSocket.onTextMessageReceived.connect(function( data ) {
                //recive client message
                var obj = JSON.parse(  data );

                //console.log( obj );
                webSocket.sendTextMessage( data  );

                //trigger
                //webView.runJavaScript( "runmyjs('alex_test')" , function(){});
            });
        }
        onErrorStringChanged: {
            console.log( "server error :" + errorString )
        }
    }

    WebView {
        id: webView
        width: Screen.width
        height: Screen.height
        url:  "file:///" + baseUrl + "?socketurl=" + server.url
    }
}
