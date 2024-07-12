<template>
  <div>
    <h1>无人机飞控</h1>
    <button @click="sendCommand('TAKEOFF')">起飞</button>
    <button @click="sendCommand('LAND')">降落</button>
    <button @click="sendCommand('MOVE_UP')">上升</button>
    <button @click="sendCommand('MOVE_DOWN')">下降</button>
    <button @click="sendCommand('MOVE_LEFT')">左移</button>
    <button @click="sendCommand('MOVE_RIGHT')">右移</button>
    </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      action: '',
    };
  },
  methods: {
    async sendCommand() {
      const command = {
        action: this.action,
      };

      try {
        const response = await axios.post('http://localhost:5000/uav/send-command', command);
        console.log(response.data);
      } catch (error) {
        console.error('发送失败:', error);
      }
    },
  },
};
</script>
