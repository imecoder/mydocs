# linux上hardhat下载sol编译器时需要配置代理

```bash
yarn hardhat compile
```

此时如果没有socl编译器，hardhat回去自动下载 `hardhat.config.ts`中配置的编译器及依赖版本，在linux上会如下问题：

> Error HH502: Couldn't download compiler versions list. Please check your connection.



- 解决办法如下

```bash
export HTTPS_PROXY=http://127.0.0.1:8118
export HTTP_PROXY=http://127.0.0.1:8118
```

> 这里hardhat只认大写！只认大写！只认大写！

