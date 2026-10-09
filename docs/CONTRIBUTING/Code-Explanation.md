# 代码说明

这是主要代码组件如何组织的一份粗略"目录"概览：

    renderdoc/ 
        CMakeLists.txt           ; cmake 文件，会递归进入子目录来构建它们
        renderdoc.sln            ; 用于 windows 构建的 VS2015 解决方案
        renderdoc/
            3rdparty/            ; 包含的第三方工具和库
            drivers/             ; 各 API 专用的后端，可单独跳过/移除
            ...                  ; 这里面的其他所有内容构成 renderdoc 核心运行时
        renderdoccmd/            ; 一个小型 C++ 实用程序，运行各种小任务
        renderdocshim/           ; 一个仅使用 kernel32.dll 的极小 C DLL，用于全局挂钩
        qrenderdoc/              ; 构建在 renderdoc/ 之上的 Qt 界面层
        docs/                    ; .chm 文件或 http://docs.renderdoc.org/ 的源文档
        util/                    ; 实用/支持文件的文件夹 - 例如构建脚本、安装程序、CI 配置