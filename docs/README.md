# RenderDoc 文档

本 readme 只涉及文档部分。关于 renderdoc 的通用信息，请查看[主 github 仓库](https://github.com/baldurk/renderdoc)。

## 生成文档

生成文档需要与构建你正在测试的 RenderDoc 版本相同的 python 版本。在 windows 上这很可能是 python 3.6，因为随仓库提供的就是它。

文档使用 restructured text 配合 [Sphinx](http://www.sphinx-doc.org/en/master/)。Sphinx 可以通过 `pip install Sphinx` 获取。

要生成文档，运行本文件夹中的 make.bat 或 make.sh。运行 `make help` 可以查看所有选项，不过 `make html` 通常是个不错的起点。

许可证
--------------

RenderDoc 采用 MIT 许可证发布，完整细节见[主 github 仓库](https://github.com/baldurk/renderdoc)。

文档使用 [Sphinx](http://www.sphinx-doc.org/en/master/)，它采用 BSD 许可证。