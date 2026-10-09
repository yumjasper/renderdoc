# SPIR-V 开源插件构建

这些脚本用于构建最新版本的 glslang、SPIRV-Cross 和 SPIRV-Tools，作为插件分发。在 windows 上这其实只是常规构建，在 linux 上它会在 renderdoc docker 中以静态链接方式构建，以确保最大兼容性。

**大多数用户不需要构建这个。** 预先构建好的最新插件包在线提供，并包含在每次构建中，你可以自行下载：

* Windows：https://renderdoc.org/plugins.zip
* Linux：https://renderdoc.org/plugins.tgz

这些脚本放在这里只是为了让 RenderDoc 开发者在需要时能更新插件。