# RenderDoc 测试

本 readme 只具体涉及测试系统。关于 renderdoc 的通用信息，请查看[主 github 仓库](https://github.com/baldurk/renderdoc)。

## 构建 demos

很多测试依赖一个 'demos' 程序，其中包含一组小型、自包含的 API 使用示例。

要在 windows 上构建，打开 `demos.sln` 并编译。没有必需的外部依赖。

要在 linux 或 Apple 上构建，用 cmake 配合 `demos/CMakeLists.txt` 编译，即

```
cmake -Bbuild -Hdemos
make -C build
```

在 linux 上你需要 `libX11`、`libxcb` 和 `libX11-xcb`。构建带 GL 支持的 RenderDoc 也需要这些，所以你很可能已经有了。

**注意：**目前有一个软性的外部依赖。如果没有把 shaderc 链接进 demos 程序，它会期望能在运行时运行 `glslc` 来把着色器编译为 SPIR-V。没有它，某些测试将被禁用。

目前只有 windows 支持链接 shaderc，如果在相对于 `$VULKAN_SDK` 环境变量的位置找到它，就会自动链接。

在 linux 或 Apple 上运行测试，你需要修改 `PATH` 变量以包含 demos_x64 构建输出的位置；另外也可以用 `--demos-binary` 选项指定 `demos_x64` 的文件路径。

## 运行测试

运行测试需要与构建你正在测试的 RenderDoc 版本相同的 python 版本。在 windows 上这很可能是 python 3.6，因为随仓库提供的就是它。

**注意：**对于 windows 用户，你还需要匹配位数，所以测试 64 位 RenderDoc 构建需要 64 位 python 安装，32 位同理。

然后运行测试意味着带上你需要的任何选项调用 `run_tests.py`：

* `--renderdoc` 和 `--pyrenderdoc` 是常用参数，分别用于修改 OS 库搜索路径和 python 模块路径以定位正确的库。例如在 windows 上 `--pyrenderdoc /path/to/renderdoc/x64/Development/pymodules --renderdoc /path/to/renderdoc/x64/Development`。
* `-l` 或 `--list` 会列出可用测试然后退出。
* `-t` 或 `--test_include` 接受一个参数，给出要包含的测试的正则表达式。只有匹配该正则的测试会被包含。如果省略，将运行所有测试。
* `-x` 或 `--test_exclude` 接受一个参数，给出要排除的测试的正则表达式。任何匹配该正则的测试都会被排除。如果省略，将运行所有测试。
* `--in-process` 会让测试在同一个 python 进程中运行。默认情况下，每个测试会创建一个子 python 进程，这样如果测试崩溃就不会拖垮整轮运行。主要用于调试。
* `--slow-tests` 包含被标记为可能长时间运行的测试。默认情况下它们被排除，以便做快速测试运行。
* `--data` 参考数据文件夹的路径，默认为此脚本旁边的 `data/`。
* `--artifacts` 输出产物文件夹的路径，默认为此脚本旁边的 `artifacts/`。
* `--temp` 临时工作文件夹的路径，默认为此脚本旁边的 `tmp/`。
* `--data-extra` 额外数据文件夹的路径。有些测试可能引用无法提交到此仓库、而是单独分发或由用户自定义添加的抓帧文件。默认指向此脚本旁边的 `data_extra/`。
* `--demos-binary` 构建出的 demos 二进制的路径。
* `--adb-device` 在其上运行测试的 ADB 设备，而非主机。如果设置，`--demos-binary` 应指向 demo APK。

**注意：**运行时，临时文件夹和产物文件夹将被清空。

一次运行之后，产物文件夹包含输出日志。它基本是纯文本，但带有 javascript，以便在浏览器中良好显示。查看日志和任何图像差异所需的所有依赖都在它旁边，所以产物文件夹是自包含的。

## 添加测试

demos 项目包含辅助库，所以最好的入门方式是复制粘贴一个现有测试，然后按你的需要修改它。避免做超级 demo，尽量只做一件简单的事。

测试也一样，它们常常与 demo 一一对应，你可以复制粘贴一个现有测试并加入你自己的检查。

当添加需要与参考图像比较的测试时，先在无参考图像的情况下运行第一次。它会输出将要用于比较的图像。把这张图像通过 pngcrush 处理（确保保留 RGBA 输出）以减少仓库膨胀。

许可证
--------------

RenderDoc 采用 MIT 许可证发布，完整细节见[主 github 仓库](https://github.com/baldurk/renderdoc)。

测试使用 [GLAD](https://github.com/Dav1dde/glad) 进行扩展加载，它采用 MIT 许可证。使用 [LZ4](https://github.com/lz4/lz4) 进行压缩，它采用 BSD 许可证。使用 [volk](https://github.com/zeux/volk) 加载 vulkan，它采用 MIT 许可证。使用 [nuklear](https://github.com/vurtun/nuklear) 实现启动器界面，它采用 MIT 许可证。使用 [shaderc](https://github.com/google/shaderc) 构建 SPIR-V 着色器，它采用 Apache-2.0 许可证。

python 测试使用 [pypng](https://github.com/drj11/pypng) 作为纯无依赖的 python png 加载/保存库，它采用 MIT 许可证。

一段来自 [Caminandes](http://www.caminandes.com/) 的短片，在 [Creative Commons Attribution 3.0 license (CC) caminandes.com](http://www.caminandes.com/sharing/) 下可用，被用作演示视频。