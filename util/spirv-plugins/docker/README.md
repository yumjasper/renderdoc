本文件夹创建一个 docker 容器，预先配置好以尽可能旧的发行版来编译 RenderDoc 的 SPIR-V 插件，从而获得二进制构建的最大兼容性。

它除针对其依赖做了定制外，不包含任何 RenderDoc 专有的内容。它依赖常规构建脚本中的 renderdoc-build。