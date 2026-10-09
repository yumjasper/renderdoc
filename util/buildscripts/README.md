# 构建脚本

本文件夹中的 build.sh 用于在 windows 和 linux 上构建打包版的 renderdoc。

在 windows 上唯一受支持的环境是 MSYS2 bash shell，其他 shell 也许可用，但为支持它们所做的修改不太可能被接受。

运行 build.sh 会打印用法说明。它可以从任何位置运行。

默认情况下它会编译所有东西并打包，这在全新 checkout 上就能工作。你也可以传入 --skipcompile 来打包已经构建好的二进制文件，但这种情况要确保所有东西都按预期编译好了：

* 在 windows 上，必须构建 Win32 和 x64 的 Release 目标。
* 在 windows 上，必须构建 `htmlhelp` 文档目标，在 Linux 上是 `html` 目标。
* 在所有平台上，根目录下的 `build-android-arm32` 子文件夹中必须存在一个 arm32 android 构建，arm64 同理。
* 在 linux 上，cmake 构建必须 `make installed` 到根目录下的 `dist` 文件夹。

如上所述，默认运行 build.sh 会编译所有这些。

# 运行

运行 build.sh 除可选参数外还必须传入 `--snapshot <name>`。该名称用于打包，即生成的 zip 将是 `RenderDoc_name.zip`。

输出文件会被放在根目录下的 `package` 子文件夹中。

`gpg` 用于为文件生成签名，所以应配置好公私钥。

# 额外内容

可以使用一些额外文件，见 `support` 子文件夹。另外 https://renderdoc.org/plugins.zip 包含 windows 插件，https://renderdoc.org/plugins.tgz 包含 linux 插件。把它们解压到仓库根目录就会包含在打包构建中。

在 windows 上，可以通过在根目录解压 https://renderdoc.org/qrenderdoc_3rdparty.zip 把 PySide2 包含进 Qt 构建中。

对于 windows 构建安装程序，所有这些额外内容都必须存在。

# 要求

除了原生和 android 构建的常规构建要求外，windows 还需要 WiX 工具集来生成安装程序文件。

Linux 需要 docker 以在隔离容器中构建工具，从而获得最大兼容性，不过使用前面提到的 `--skipcompile`，你可以通过本地构建来绕过这一点。

两个平台都要求 python 中有 sphinx，此外 windows 还需要 HTML help workshop。