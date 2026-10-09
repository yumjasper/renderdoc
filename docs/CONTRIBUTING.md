# 为 RenderDoc 贡献

本文档被拆分并组织成若干章节，以便阅读和链接。对于像一行修复或小调整这样的小改动，你只需要阅读下面的[快速开始](#quick-start)章节即可。

不用担心里程碑式的从头到尾读完所有文档、第一次就做到完美。这些信息的目的不是用规则来限制和拒绝贡献，而是给人们提供如何贡献的指引和帮助。我很乐意帮忙处理让你的 PR 达到可合并状态所需的任何改动，直到你熟悉为止。如果你不熟悉 git、需要帮助来做出任何改动，也随时可以来问！

如果你是常规贡献者，或者有较多代码要改，请务必把这些读一遍，因为你从一开始就遵循这些准则，会让所有人的工作都更轻松。

## 行为准则

我希望确保任何人都能为 RenderDoc 做贡献，而只需担心下一个 bug。因此项目采用了 [contributor covenent](CODE_OF_CONDUCT.md) 作为行为准则，对参与 RenderDoc 开发的每个人都强制执行。这包括对 issue 的任何评论，或任何公开讨论，例如在 #renderdoc IRC 频道或 discord 服务器中。

如果你在这方面有任何疑问或顾虑，可以[直接通过邮件](mailto:baldurk@baldurk.org)联系我。

## 关于 LLM / "AI" 的使用

严格禁止将 LLM 或任何类似技术用于任何贡献给 RenderDoc 的代码。此规则没有例外。

## RenderDoc 的合理使用

RenderDoc 是一个用于调试你自己的项目和程序的工具，是那些你真正拥有所有权的项目。不允许将 RenderDoc 用于非法或不道德的用途，包括但不限于捕获你不拥有版权的受版权保护的程序。与任何此类用途相关的任何问题或事项都将不予回答，也不提供任何支持。

## 版权 / 贡献者许可协议

你提交的任何代码都会成为仓库的一部分，并在 [RenderDoc 许可证](../LICENSE.md) 下分发。通过向项目提交代码，你同意该代码是你自己的作品，并且你有能力将它贡献给项目。

你还需要通过提交代码，同意将代码的所有可转让权利授予项目维护者，例如包括重新授权代码、修改代码、以源码或二进制形式分发。具体来说，这包括你须将版权转让给项目维护者（Baldur Karlsson）。因此，不要在任何 PR 中修改文件里的版权声明。

## 贡献信息

1. [依赖](CONTRIBUTING/Dependencies.md)
2. [编译](CONTRIBUTING/Compiling.md)
3. [准备提交](CONTRIBUTING/Preparing-Commits.md)
4. [开发一个改动](CONTRIBUTING/Developing-Change.md)
5. [测试](CONTRIBUTING/Testing.md)
6. [代码说明](CONTRIBUTING/Code-Explanation.md)
7. [提交 issue](CONTRIBUTING/Filing-Issues.md)
8. [提问](CONTRIBUTING/Questions.md)

## 快速开始

对于小改动，你需要注意两件事：[提交信息](CONTRIBUTING/Preparing-Commits.md#commit-messages)和[代码格式](CONTRIBUTING/Preparing-Commits.md#code-formatting)。

提交信息的第一行应**最多 72 个字符**，然后空一行，如果你需要的话再写更长的说明，格式随你。这样做的原因是，把第一行限制在 72 个字符内，可以让 `git log` 和 github 的历史记录始终完整显示信息而不会被截断。

更多信息请查看[提交信息](CONTRIBUTING/Preparing-Commits.md#commit-messages)章节。

代码应使用 **clang-format 15.0** 进行格式化。我们固定一个特定版本的 clang-format，是因为遗憾的是不同版本用相同的配置文件可能会以不同方式格式化代码，这会给代码格式的自动校验带来问题。

更多信息请查看[代码格式](CONTRIBUTING/Preparing-Commits.md#code-formatting)章节。

**不要**创建"草稿（draft）"pull request。这是 github 一个毫无意义的反功能，没有任何价值，也没有任何用途。如果你的代码还没准备好合并，那就根本不要创建 pull request。