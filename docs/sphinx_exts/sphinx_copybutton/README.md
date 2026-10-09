# sphinx-copybutton

[![PyPI](https://img.shields.io/pypi/v/sphinx-copybutton.svg)](https://pypi.org/project/sphinx_copybutton/) | [![Conda Version](https://img.shields.io/conda/vn/conda-forge/sphinx-copybutton.svg)](https://anaconda.org/conda-forge/sphinx-copybutton) | [![Documentation](https://readthedocs.org/projects/sphinx-copybutton/badge/?version=latest)](https://sphinx-copybutton.readthedocs.io/en/latest/?badge=latest)

一个小型 sphinx 扩展，用于给代码块添加"复制"按钮。

更多细节见 [sphinx-copybutton 文档](https://sphinx-copybutton.readthedocs.io/en/latest/)！

![Copy Button Demo](https://user-images.githubusercontent.com/1839645/150200219-73663c59-08fd-4185-b157-62f3769c02ac.gif)

## 安装

你可以用 `pip` 安装 `sphinx-copybutton`：

```bash
pip install sphinx-copybutton
```

或者通过 `conda-forge` 用 `conda` 安装：

```bash
conda install -c conda-forge sphinx-copybutton
```


## 用法

在你的 `conf.py` 配置文件中，把 `sphinx_copybutton` 加到扩展列表里。
例如：

```python
extensions = [
    ...
    'sphinx_copybutton'
    ...
]
```

构建站点时，你的代码块右侧就应该出现小小的复制按钮。点击按钮就会复制其中的代码！

## 自定义

如果你想自定义复制按钮的外观，可以覆盖 Sphinx-CopyButton CSS 文件中指定的任何 CSS 规则（[链接](sphinx_copybutton/_static/copybutton.css)）

## 开发

开发应主要遵循 [EBP 开发者约定](https://github.com/executablebooks/.github/blob/master/CONTRIBUTING.md)

Sphinx-Copybutton [托管在 pypi 仓库上](https://pypi.org/project/sphinx-copybutton/)。
发布之后，按照 [EBP 发布说明](https://github.com/executablebooks/.github/blob/master/CONTRIBUTING.md#releases-and-change-logs)，确认新版本的 Sphinx-Copybutton [已发布到 pypi](https://pypi.org/project/sphinx-copybutton/)。

## 致谢

非常感谢出色的 [clipboard.js 库](https://clipboardjs.com/)提供了驱动复制按钮的轻量级 javascript 代码！