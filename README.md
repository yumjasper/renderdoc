<p align="center"><img src="https://user-images.githubusercontent.com/661798/36482670-f81601c0-170b-11e8-8adb-2365b346ac27.png" /></p>

[![MIT licensed](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE.md)
[![CI](https://github.com/baldurk/renderdoc/actions/workflows/ci.yml/badge.svg?branch=v1.x&event=push)](https://github.com/baldurk/renderdoc/actions)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.0%20adopted-ff69b4.svg)](docs/CODE_OF_CONDUCT.md) 

RenderDoc 是一款基于帧捕获（frame capture）的图形调试器，目前可用于在 Windows、Linux、Android 和 Nintendo Switch&trade; 上开发 Vulkan、D3D11、D3D12、OpenGL 和 OpenGL ES。它完全开源，采用 MIT 许可证。

RenderDoc 仅用于调试你自己的程序。在任何官方的 RenderDoc 公共场合（包括 issue tracker、discord 或邮件），都不允许讨论捕获你不曾创建的程序。例如，这包括捕获你并未创建的商业游戏，或捕获 Google Maps、Google Earth。注意：捕获你自己创建、但使用了 Unreal 或 Unity 等第三方引擎的项目，或者捕获开源和免费项目，都是完全可以的，也受到支持。

如果你有任何疑问、建议或问题，可以在这里的 github 上[创建一个 issue](https://github.com/baldurk/renderdoc/issues/new/choose)、[直接给我发邮件](mailto:baldurk@baldurk.org)，或者加入 [IRC](https://webchat.oftc.net/?channels=renderdoc) 或 [Discord](https://discord.gg/ahq6yRB) 一起讨论。

在 Windows 上安装，请运行适合你操作系统的安装程序（[64 位](https://renderdoc.org/stable/latest/RenderDoc_latest_64.msi) | [32 位](https://renderdoc.org/stable/latest/RenderDoc_latest_32.msi)），或者从[构建页面](https://renderdoc.org/builds)下载便携版 zip。64 位 Windows 版本完整支持从 32 位程序捕获。Linux 上只支持 64 位 x86，有预编译的[二进制压缩包](https://renderdoc.org/stable/latest/renderdoc_latest.tar.gz)可用，你的发行版也可能已经打包。如果没有，你可以[从源码构建](docs/CONTRIBUTING/Compiling.md)。

* **下载**：稳定版和每日构建版：https://renderdoc.org/builds （[符号服务器](https://renderdoc.org/symbols)）
* **文档**：[在线 HTML](https://renderdoc.org/docs)、[构建包内的 CHM](https://renderdoc.org/docs/renderdoc.chm)、[视频](https://www.youtube.com/user/baldurkarlsson)
* **联系方式**：[baldurk@baldurk.org](mailto:baldurk@baldurk.org)、[OFTC IRC 上的 #renderdoc](https://webchat.oftc.net/?channels=renderdoc)、[Discord 服务器](https://discord.gg/ahq6yRB)
* **行为准则**：[Contributor Covenant](docs/CODE_OF_CONDUCT.md)
* **贡献者信息**：[所有贡献信息](docs/CONTRIBUTING.md)、[编译说明](docs/CONTRIBUTING/Compiling.md)
* **社区扩展**：[扩展仓库](https://github.com/baldurk/renderdoc-contrib)

截图
--------------

| [ ![Texture view](https://renderdoc.org/fp/ts_screen1.jpg?2) ](https://renderdoc.org/fp/screen1.jpg) | [ ![Pixel history & shader debug](https://renderdoc.org/fp/ts_screen2.jpg?2) ](https://renderdoc.org/fp/screen2.png) |
| --- | --- |
| [ ![Mesh viewer](https://renderdoc.org/fp/ts_screen3.jpg?2) ](https://renderdoc.org/fp/screen3.png) | [ ![Pipeline viewer & constants](https://renderdoc.org/fp/ts_screen4.jpg?2) ](https://renderdoc.org/fp/screen4.png) |

API 支持情况
--------------

|                          | Windows                  | Linux                    | Android                   |
| ------------------------ | ------------------------ | ------------------------ | ------------------------  |
| Vulkan                   | :heavy_check_mark:       | :heavy_check_mark:       | :heavy_check_mark:        |
| OpenGL ES 2.0 - 3.2      | :heavy_check_mark:       | :heavy_check_mark:       | :heavy_check_mark:        |
| OpenGL 3.2 - 4.6 Core    | :heavy_check_mark:       | :heavy_check_mark:       |  N/A                      |
| D3D11 & D3D12            | :heavy_check_mark:       |  N/A                     |  N/A                      |
| OpenGL 1.0 - 2.0 Compat  | :heavy_multiplication_x: | :heavy_multiplication_x: |  N/A                      |
| D3D9 & 10                | :heavy_multiplication_x: |  N/A                     |  N/A                      |
| Metal                    |  N/A                     |  N/A                     |  N/A                      |

* Nintendo Switch&trade; 的支持作为 NintendoSDK 的一部分，面向授权开发者单独分发。更多信息请咨询 Nintendo 开发者门户。

下载
--------------

这里有[二进制发行版](https://renderdoc.org/builds)，由发布目标构建而来。如果你只是想使用这个程序，却一路看到了这里，那么这就是你想要的 :)。

如果你是新用户，建议从稳定版开始。如果你需要，每日构建版每天都会在 [v1.x 分支](https://renderdoc.org/builds#nightly)提供，但相应地可能不太稳定。

文档
--------------

文本文档提供[最新稳定版在线版本](https://renderdoc.org/docs/)，以及任何构建包中都可找到的 [renderdoc.chm](https://renderdoc.org/docs/renderdoc.chm)。它由 [sphinx 处理 restructured text](docs) 生成。

如上所述，还有一些 [youtube 视频](https://www.youtube.com/user/baldurkarlsson)，演示了一些基本功能的用法，以及介绍和概览。

还有 [@Icetigris](https://twitter.com/Icetigris) 做的一个很棒的演讲，深入探讨了 RenderDoc 在真实场景中如何使用：[幻灯片在这里](https://docs.google.com/presentation/d/1LQUMIld4SGoQVthnhT1scoA3k4Sg0as14G4NeSiSgFU/edit#slide=id.p)。

许可证
--------------

RenderDoc 采用 MIT 许可证发布，完整文本以及第三方库致谢见 [LICENSE.md](LICENSE.md)。

编译
---------

在大多数平台上构建 RenderDoc 都相当直接。更多细节见 [Compiling.md](docs/CONTRIBUTING/Compiling.md)。

贡献与开发
--------------

我在 [Developing-Change.md](docs/CONTRIBUTING/Developing-Change.md) 中写了一些关于如何贡献、以及从哪里开始阅读代码的说明。所有贡献信息都可以在 [CONTRIBUTING.md](docs/CONTRIBUTING.md) 中找到。