# 编译

## Windows

主要的 [renderdoc.sln](renderdoc.sln) 是 VS2015 解决方案。它也应该能在更高的 VS 版本中编译，如果你没有 2015 编译器，只需选择更新编译器即可。

除了 Windows SDK 之外没有外部依赖，任何版本都可以；构建所需的所有库/头文件都包含在 git checkout 中。

在 windows 上，日常开发推荐使用 `Development` 配置。它可调试，但也不会太慢。而 `Release` 配置显然是你向他人发送任何构建、或想评估性能时应该编译的版本。

## Linux

首先检查你是否具备所有[必需的依赖](Dependencies.md#linux)。

RenderDoc 只支持在 64 位 x86 linux 上构建。不支持 32 位 x86 以及任何 ARM 或其他平台。

目前 linux 应可与 gcc 5+ 和 clang 3.4+ 一起工作，因为它需要 C++14 编译器支持。CI 使用 gcc-5.0 和 clang-3.8 构建。只要所需补丁最小，其他编译器在合理范围内也会被支持。发行版软件包应使用 `Release` CMake 构建类型构建，以免警告触发错误。要构建，只需运行：

```
cmake -DCMAKE_BUILD_TYPE=Debug -Bbuild -H.
make -C build
```

cmake 的配置可用，[在别处有文档](https://cmake.org/documentation/)。你可以用环境变量 `CC` 和 `CXX` 覆盖编译器，根 CMakeLists 文件中还有一些可以切换的选项，例如 `cmake -DENABLE_GL=OFF`。

## Mac

首先检查你是否具备所有[必需的依赖](Dependencies.md#mac)。

Mac 支持还相当初级，虽然能编译，但尚不可用于调试，也未正式支持。

要用 make 构建，像 Linux 一样使用 cmake。

要用 Xcode 构建，使用 cmake 的 Xcode 生成器创建 Xcode 项目：

```
cmake -DCMAKE_BUILD_TYPE=Debug -Bbuild -H. -GXcode
```

为 Mac 构建需要符合 C++17 的编译器，也就是 Xcode 的 clang 编译器。

## Android

首先检查你是否具备所有[必需的依赖](Dependencies.md#android)。

要构建调试 Android 目标所需的组件，调用 cmake 并启用 `BUILD_ANDROID=On`：

```
mkdir build-android
cd build-android
cmake -DBUILD_ANDROID=On -DANDROID_ABI=armeabi-v7a ..
make
```

在 Windows 上，你应始终从 bash shell（cygwin、msys2、Windows WSL 等）构建 Android。从 cmd 构建也许可行但不受支持。

在 windows 的 cmake 上，你需要向 cmake 调用指定 'generator' 类型。确切参数取决于你的 bash shell，选项例如 `-G "MSYS Makefiles"` 或 `-G "MinGW Makefiles"`，即：

```
cmake -DBUILD_ANDROID=On -DANDROID_ABI=armeabi-v7a -G "MSYS Makefiles" ..
```

### 注意：

使用 Android 上的 GLES 程序时，内置的挂钩（hooking）方法并不总是有效。如果你在捕获 GLES 程序时遇到崩溃或问题，可以尝试启用 [interceptor-lib](../../renderdoc/3rdparty/interceptor-lib/README.md) 构建。**警告**：构建它需要一个庞大的依赖。