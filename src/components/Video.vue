<template>
  <div>
    <video id="myPlayer" class="video-js vjs-default-skin" controls></video>
  </div>
</template>

<script>
import videojs from 'video.js';
import 'video.js/dist/video-js.css';
import flvjs from 'flv.js';

export default {
  mounted() {
    this.player = videojs('myPlayer', {
      techOrder: ['html5', 'flvjs'],
      sources: [{
        src: 'YOUR_FLV_STREAM_URL', // 这里换成实际的FLV流URL
        type: 'video/x-flv'
      }],
      controlBar: { // 自定义控制栏
        fullscreenToggle: true,
      },
    });

    // 检查flvjs是否可用并加载流
    if (flvjs.isSupported()) {
      const tech = flvjs.createPlayer({
        type: 'flv',
        url: 'YOUR_FLV_STREAM_URL', // 与sources.src相同，确保一致
      });
      this.player.tech_.hls = tech;
      tech.attachMediaElement(this.player.el().querySelector('video'));
      tech.load();
    } else {
      console.error('FLV.js is not supported in this browser.');
    }
  },
  beforeDestroy() {
    if (this.player && this.player.dispose) {
      this.player.dispose();
    }
  },
};
</script>