# 构建静态 clang-format

docker 脚本会构建并静态链接 clang-format，生成一个可移植的静态链接二进制文件。

```
docker run --rm -v $(pwd):/script:ro -v $(pwd):/out ubuntu:jammy bash /script/build.sh
```