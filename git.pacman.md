# windows上，git中安装pacman

## 1. git安装(略)

## 2. 下载pacman相关文件

### pacman（需要将usr/bin 中的 pacman.exe 改为 pacman）：pacman 主包

	https://packages.msys2.org/package/pacman?repo=msys&variant=x86_64

### pacman-mirrors：源

	https://packages.msys2.org/package/pacman-mirrors?repo=msys&variant=x86_64

### msys2-keyring：源秘钥

	https://packages.msys2.org/package/msys2-keyring?repo=msys&variant=x86_64

使用peazip进行解压，直接解压到 git 安装根目录中。

## 3. 刷新

**[以管理员身份运行]** git-bash, 运行如下命令：

```bash
# 刷新秘钥
pacman-key --init
pacman-key --refresh-keys
pacman-key --populat

# 清除缓存
pacman -Sc

# 更新系统，也可以不更新
pacman -Syu
```

完成。