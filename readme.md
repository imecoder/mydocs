# 开发工具配置

## windows中配置mingw64开发环境

- 安装msys2工具（略）

- 安装开发工具链

  ```bash
  pacman -S mingw-w64-x86_64-toolchain
  pacman -S mingw-w64-x86_64-cmake
  pacman -S mingw-w64-x86_64-clang 
  ```

- 为开发文件配置头文件

  开启

  ```bash
  ln -s /mingw64/include /mingw64/x86_64-w64-mingw32/include
  ```

## 在Clion中配置MinGW

![001](clion\001.png)

![002](clion\002.png)