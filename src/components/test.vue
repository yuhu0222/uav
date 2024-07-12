<template>
  <div>
    <video ref="video" autoplay></video>
  </div>
</template>

<script>
import Vue from 'vue'
import VueWebRTC from 'vue-webrtc'

Vue.use(VueWebRTC)

export default {
  name: 'VideoPlayer',
  mounted() {
    this.initWebRTC();
  },
  methods: {
    async initWebRTC() {
      const video = this.$refs.video;
      const pc = new RTCPeerConnection({
        iceServers: [{ urls: 'stun:stun.l.google.com:19302' }]
      });

      this.pc.onicecandidate = event => {
        if (event.candidate) {
          this.socket.send(JSON.stringify({
            type: 'candidate',
            candidate: event.candidate
          }));
        }
      };

      pc.ontrack = event => {
        video.srcObject = event.streams[0];
      };

      // Get the stream from the WebRTC server
      try {
        const response = await fetch('ws://localhost:8080');
        const data = await response.json();
        await pc.setRemoteDescription(new RTCSessionDescription(data.sdp));
        for (const candidate of data.candidates) {
          await pc.addIceCandidate(new RTCIceCandidate(candidate));
        }
      } catch (error) {
        console.error('Error during signaling:', error);
      }
    }
  }
}
</script>

<style>
video {
  width: 100%;
  height: auto;
}
</style>
