
const char webpageCode[] PROGMEM =
  R"=====(
<!DOCTYPE HTML>
<html>
<head>
  <title>ESP32 Web Server</title>
</head>
<!-------------------------------C S S------------------------------>
<style>
  #btn {
        display: inline-block;
        text-decoration: none;
        background: #d71337;
        color: rgba(255, 255, 255, 0.80);
        font-weight: bold;
        font: 50px arial, sans-serif;
        width: 110px;
        height: 110px;
        line-height: 100px;
        border-radius: 50%;
        text-align: center;
        vertical-align: middle;
        overflow: hidden;
        box-shadow: 0px 0px 0px 8px #768a6a;
        border: solid 2px rgba(255, 255, 255, 0.47);
        transition: background 0.5s ease;
    }
  body {text-align:center; font-family:"Calibri"; background-color:rgba(0, 3, 8, 0.26)}
  h1   {color: rgba(0, 0, 255, 0.87); font-size: 50px;}
</style>
<!------------------------------H T M L----------------------------->
<body>
   <h1>E S P 3 2<br>WebSocket Server</h1>
   <a href="#" id="btn" ONCLICK='button()'> </a>
<!-----------------------------JavaScript--------------------------->
  <script>
  var ledState = false;
        var led1 = document.getElementById('btn');
     InitWebSocket()
     function InitWebSocket()
     {
       websock = new WebSocket('ws://'+window.location.hostname+':81/'); 
       websock.onmessage = function(evt)
       {
          JSONobj = JSON.parse(evt.data);
          document.getElementById('btn').innerHTML = JSONobj.LEDonoff;
          if(JSONobj.LEDonoff == 'ON')
          {
            led1.style.background = '#60d817';
                led1.style["boxShadow"] = "0px 0px 0px 8px #768a6a";
          }
          else
          {
             led1.style.background = '#d71337';
                led1.style["boxShadow"] = "0px 0px 0px 8px #768a6a";
          }
       }
     }
     //-------------------------------------------------------------
     function button()
     {
        btn = 'LEDonoff=ON';
        if(led1.innerHTML == 'ON')
        {
          btn = 'LEDonoff=OFF';
        }
        websock.send(btn);
     }
  </script>
</body>
</html>
)=====";
