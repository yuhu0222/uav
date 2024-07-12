const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  transpileDependencies: true,
   //关闭语法检查
   lintOnSave:false,

   devServer: {
    proxy: {
      '/socket': {
        target: 'ws://localhost:8085',
        ws: true,
        changeOrigin: true,
        pathRewrite: { '^/socket': '' },
      },
    },
  },
})

