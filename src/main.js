import Vue from 'vue'
import App from './App.vue'
import '../src/components/jsmpeg.min.js'

Vue.config.productionTip = false

new Vue({
  render: h => h(App),
}).$mount('#app')
