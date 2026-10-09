本文件夹包含各种未随构建脚本提供、但可以使用的文件。

* dbghelp.dll、pdbstr.exe、symstore.exe、symsrv.dll、symsrv.yes - 用于搭配构建出的符号设置源码服务器和符号库（symbol store）。取自 Windows 10 SDK 的 Debuggers/x64 文件夹
* key.pfx、key.pass - 用于对生成的二进制文件签名
* llvm_arm32、llvm_arm64 - 用于通过 interceptor-lib 构建 android。
* emailhost - 一个可选文件，包含一个 ssh 兼容的 user@host 字符串，用于发送错误邮件（邮件通过在该远程主机上运行 'mail' 发送）