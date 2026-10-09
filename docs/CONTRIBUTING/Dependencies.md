# 依赖

（依赖安装完成后，请见 [Compiling.md](Compiling.md)）

## Windows

在 Windows 上没有任何依赖，你只要下载代码并在 Visual Studio 中编译解决方案，就能编译最新版本。如果你想用所见即所得（WYSIWYG）编辑器修改 Qt 界面，则需要安装一个 Qt 版本，至少 5.6。

## Linux

RenderDoc 只支持在 64 位 x86 linux 上构建。不支持 32 位 x86 以及任何 ARM 或其他平台。

核心库和 renderdoccmd 的需求是 `libx11`、`libxcb`、`libxcb-keysyms` 和 `libGL`。它们对应的确切软件包因发行版而异。

对于 qrenderdoc，你需要 Qt5 >= 5.6 以及 'svg' 和 'x11extras' 包。你还需要 `python3-dev` 用于 python 集成，以及 `bison`、`autoconf`、`automake` 和 `libpcre3-dev` 用于构建生成绑定的自定义 SWIG 工具。

在任何发行版上，如果你发现 qmake 不在其默认名称下可用，或者 `qmake -v` 列出的 Qt4 版本，请确保你的包管理器中安装了 qtchooser 并用它选择 Qt5。这可以通过导出 `QT_SELECT=qt5` 完成，但具体细节请与你的发行版确认。

对于某些发行版（如 CentOS 和 Fedora），Qt5 的 qmake 命令是 `qmake-qt5`。要显式选择它，在调用 `cmake` 时传入 `-DQMAKE_QT5_COMMAND=qmake-qt5`。

下面是各发行版的具体说明。如果你知道其他发行版所需的软件包，请分享（或者给这个文件提 pull request！）

### Ubuntu

对于 Ubuntu 18.04 或更高版本，你需要：

```
sudo apt-get install libx11-dev libx11-xcb-dev mesa-common-dev libgl1-mesa-dev libxcb-keysyms1-dev pkg-config cmake python3-dev bison autoconf automake libpcre3-dev qt5-qmake libqt5svg5-dev libqt5x11extras5-dev
```

用于安装依赖。在 18.04 之前的 Ubuntu 版本上，默认软件源中的 Qt 不够新或可能缺失。你可以使用 [Stephan Binner 的 ppas](https://launchpad.net/~beineri) 安装更新的 Qt 版本。至少需要 5.6.2。如果你选择改为安装[官方 Qt 发布版](https://download.qt.io/official_releases/qt/)或从源码构建 Qt，请在你的 cmake 参数中加入 `-DQMAKE_QT5_COMMAND=/path/to/qmake`。

### Archlinux

对于 Archlinux（截至 2019.04.12），你需要：

```
sudo pacman -S libx11 libxcb xcb-util-keysyms mesa libgl qt5-base qt5-svg qt5-x11extras cmake python3 bison autoconf automake pcre make pkg-config
```

### Gentoo

对于 Gentoo（截至 2017.04.18），你需要：

```
sudo emerge --ask x11-libs/libX11 x11-libs/libxcb x11-libs/xcb-util-keysyms dev-util/cmake dev-qt/qtcore dev-qt/qtgui dev-qt/qtwidgets dev-qt/qtsvg dev-qt/qtx11extras sys-devel/bison sys-devel/autoconf sys-devel/automake dev-lang/python dev-libs/libpcre
```

确认至少安装了 Qt 5.6。

### CentOS

在 CentOS 7 上（截至 2018.01.18），你需要从多个仓库安装：

```
# 默认仓库中的依赖
yum install libX11-devel libxcb-devel mesa-libGL-devel xcb-util-keysyms-devel cmake qt5-qtbase-devel qt5-qtsvg-devel qt5-qtx11extras-devel bison autoconf automake pcre-devel

# 通过 EPEL 安装 python3
yum install epel-release
yum install python34-devel

# 通过 SCL 的 devtoolset-7 获得更新的 GCC
yum install centos-release-scl
yum install devtoolset-7
```

然后在构建时，你必须先从 SCL 启用 devtoolset-7：
```
scl enable devtoolset-7 bash
```

并在由此产生的 bash shell 中构建，此时这些工具已经位于 PATH 最前面。

### Fedora

在 Fedora 33 上（截至 2020.11.05），你需要：

```
sudo yum install libX11-devel libxcb-devel mesa-libGL-devel xcb-util-keysyms-devel cmake qt5-qtbase-devel qt5-qtsvg-devel qt5-qtx11extras-devel bison autoconf automake pcre-devel python3-devel
```

### Debian

Debian 9+（stretch）：
```
sudo apt-get install libx11-dev libx11-xcb-dev mesa-common-dev libgl1-mesa-dev libxcb-keysyms1-dev cmake python3-dev bison autoconf automake libpcre3-dev qt5-qmake libqt5svg5-dev libqt5x11extras5-dev 
```

## Mac

Mac 需要 Xcode 12.2 或更新版本、CMake 3.20 或更新版本、`autoconf`、`automake`、`pcre` 以及 Qt5 5.15.2 或更新版本。如果你使用 [homebrew](http://brew.sh)，那么这就够了：

```
brew install cmake autoconf automake pcre qt5
brew link qt5 --force
```

## Android

要为 Android 构建，你必须下载 Android SDK 的组件、Android NDK 和 Java 开发工具包（JDK）。

RenderDoc 目前已知可以使用 NDK 14b、SDK tools 3859397、SDK build-tools 26.0.1、SDK platform android-23、Java 8（也称 1.8）构建。如果你使用其中任何组件的不同版本，你需要自行确保所有组件版本兼容，否则可能会出现构建失败，因为某些组件的版本可能与其他组件（甚至更新）的版本不兼容。

如果你已经具备所需的工具，只需设置以下三个环境变量：

```
export ANDROID_SDK=<path_to_sdk_root>
export ANDROID_NDK=<path_to_ndk_root>
export JAVA_HOME=<path_to_jdk_root>
```

你还必须确保 `JAVA_HOME` 中的 `java` 在你的 `PATH` 中，因为某些 Android 构建命令会直接运行 java 而不遵循 `JAVA_HOME`。

否则，下面是各平台获取工具的步骤。这些步骤专门下载上面列出的版本，其他版本也许可用但不保证。

### Windows 上的 Android 依赖

JDK 8 可以从以下[链接](http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html)安装。

```
set JAVA_HOME=<path_to_jdk_root>
```

Android NDK 和 SDK：

```
# 设置 Android SDK
set ANDROID_SDK=<path_to_desired_setup>
cd %ANDROID_SDK%
wget https://dl.google.com/android/repository/sdk-tools-windows-3859397.zip
unzip sdk-tools-windows-3859397.zip
cd tools\bin
sdkmanager --sdk_root=%ANDROID_SDK% "build-tools;26.0.1" "platforms;android-23"
# 接受许可证

# 设置 Android NDK
cd %ANDROID_SDK%
wget http://dl.google.com/android/repository/android-ndk-r14b-windows-x86_64.zip
unzip android-ndk-r14b-windows-x86_64.zip
set ANDROID_NDK=%ANDROID_SDK%\android-ndk-r14b
```

### Linux 上的 Android 依赖

JDK 8 可以用以下命令安装：

```
sudo apt-get install openjdk-8-jdk
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
```

Android SDK 和 NDK 可以用以下步骤设置。

SDK 链接取自[这里](https://web.archive.org/web/20171026083141/https://developer.android.com/studio/index.html)（旧版本不再从 android 网站链接，但下载仍然有效）。

NDK 链接取自[这里](https://developer.android.com/ndk/downloads/older_releases.html)。

```
# 设置 Android SDK
export ANDROID_SDK=<path_to_desired_setup>
pushd $ANDROID_SDK
wget http://dl.google.com/android/repository/sdk-tools-linux-3859397.zip
unzip sdk-tools-linux-3859397.zip
cd tools/bin/
./sdkmanager --sdk_root=$ANDROID_SDK "build-tools;26.0.1" "platforms;android-23"
# 接受许可证

# 设置 Android NDK
pushd $ANDROID_SDK
wget http://dl.google.com/android/repository/android-ndk-r14b-linux-x86_64.zip
unzip android-ndk-r14b-linux-x86_64.zip
export ANDROID_NDK=$ANDROID_SDK/android-ndk-r14b
```

### Mac 上的 Android 依赖

JDK 可以用 brew 安装：

```
brew cask install java
export JAVA_HOME="$(/usr/libexec/java_home)"
```

Android NDK 和 SDK：

```
# 设置 Android SDK
export ANDROID_SDK=<path_to_desired_setup>
pushd $ANDROID_SDK
wget https://dl.google.com/android/repository/sdk-tools-darwin-3859397.zip
unzip sdk-tools-darwin-3859397.zip
cd tools/bin/
./sdkmanager --sdk_root=$ANDROID_SDK "build-tools;26.0.1" "platforms;android-23"
# 接受许可证

# 设置 Android NDK
pushd $ANDROID_SDK
wget http://dl.google.com/android/repository/android-ndk-r14b-darwin-x86_64.zip
unzip android-ndk-r14b-darwin-x86_64.zip
export ANDROID_NDK=$ANDROID_SDK/android-ndk-r14b
```