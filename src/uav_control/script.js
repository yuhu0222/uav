document.addEventListener("DOMContentLoaded", function() {
    const ws = new WebSocket("ws://YOUR_GROUND_STATION_IP:PORT"); // 替换成你的地面站 WebSocket 地址
  
    ws.onopen = function() {
      console.log("Connected to the ground station.");
    };
  
    ws.onmessage = function(event) {
      console.log("Message from ground station:", event.data);
    };
  
    ws.onclose = function() {
      console.log("Disconnected from the ground station.");
    };
  
    ws.onerror = function(error) {
      console.error("WebSocket error:", error);
    };
  
    function sendCommand(command) {
      if (ws.readyState === WebSocket.OPEN) {
        ws.send(JSON.stringify({ command: command }));
        console.log(`Command '${command}' sent.`);
      } else {
        console.error("WebSocket is not open.");
      }
    }
  
    document.getElementById("takeoffBtn").addEventListener("click", function() {
      sendCommand("takeoff");
    });
  
    document.getElementById("landBtn").addEventListener("click", function() {
      sendCommand("land");
    });
  
    document.getElementById("upBtn").addEventListener("click", function() {
      sendCommand("up");
    });
  
    document.getElementById("downBtn").addEventListener("click", function() {
      sendCommand("down");
    });
  
    document.getElementById("leftBtn").addEventListener("click", function() {
      sendCommand("left");
    });
  
    document.getElementById("rightBtn").addEventListener("click", function() {
      sendCommand("right");
    });
  });
  