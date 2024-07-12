#include <iostream>

const char main_html[] = 
R"(
<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>无人机控制面板</title>
    <style>
        /* 自定义CSS样式 */
        .command-button {
            margin: 5px;
            padding: 10px;
            font-size: 16px;
            cursor: pointer;
        }
        .status-container {
            margin-top: 20px;
            padding: 10px;
            border: 1px solid #ccc;
        }
    </style>
</head>
<body>
    <h1>无人机控制面板</h1>

    <div id="command-buttons">
        <button class="command-button" onclick="sendCommand('takeoff')">起飞</button>
        <button class="command-button" onclick="sendCommand('setCoordinates')">设置经纬度/海拔</button>
        <button class="command-button" onclick="sendCommand('moveUp')">上升</button>
        <button class="command-button" onclick="sendCommand('moveDown')">下降</button>
        <button class="command-button" onclick="sendCommand('moveLeft')">左移动</button>
        <button class="command-button" onclick="sendCommand('moveRight')">右移动</button>
        <button class="command-button" onclick="sendCommand('moveForward')">前移动</button>
        <button class="command-button" onclick="sendCommand('moveBackward')">后移动</button>
        <button class="command-button" onclick="sendCommand('turnLeft')">航向左</button>
        <button class="command-button" onclick="sendCommand('turnRight')">航向右</button>
        <button class="command-button" onclick="sendCommand('channel1')">通道1（抛投）</button>
        <button class="command-button" onclick="sendCommand('channel2')">通道2（发射）</button>
        <button class="command-button" onclick="sendCommand('channel3')">通道3（启动）</button>
        <button class="command-button" onclick="sendCommand('channel4')">通道4（触发）</button>
        <button class="command-button" onclick="sendCommand('returnToBase')">返航</button>
        <button class="command-button" onclick="sendCommand('returnToBackupPoint')">返航至备降点</button>
        <button class="command-button" onclick="sendCommand('takePhoto')">拍照</button>
        <button class="command-button" onclick="sendCommand('recordVideo')">录像</button>
        <button class="command-button" onclick="sendCommand('adjustGimbal')">吊舱上下调节</button>
        <button class="command-button" onclick="sendCommand('moveGimbalDown')">一键向下</button>
        <button class="command-button" onclick="sendCommand('resetGimbal')">一键回中</button>
    </div>

    <div class="status-container">
        <h2>状态:</h2>
        <p id="status-text">等待状态更新...</p>
    </div>

    <script>
        function sendCommand(command) {
            // 发送指令到无人机的逻辑（例如通过WebSocket或HTTP请求）
            console.log('发送指令:', command);

            // 模拟接收状态更新并更新状态显示
            updateStatus(`已发送指令: ${command}`);
        }

        function updateStatus(message) {
            // 更新状态显示区域
            document.getElementById('status-text').innerText = message;
        }
    </script>
</body>
</html>
)";
