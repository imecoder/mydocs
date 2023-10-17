# 合约开发工具包 —— eosio.cdt

## 工具包中包含的工具

- eosio-cpp
- eosio-cc
- eosio-ld
- eosio-init
- eosio-abidiff
- eosio-wasm2wast
- eosio-wast2wasm
- eosio-ranlib
- eosio-ar
- eosio-objdump
- eosio-readelf

## 1.6.1

- 二进制安装方式

```bash
# 下载安装包
wget https://github.com/EOSIO/eosio.cdt/releases/download/v1.6.1/eosio.cdt_1.6.1-1_amd64.deb

# 安装包
apt -y install ./eosio.cdt_1.6.1-1_amd64.deb
apt -y install -f
```

- 源码安装方式

```bash
git clone --recursive https://github.com/eosio/eosio.cdt --branch v1.6.1 --single-branch
cd eosio.cdt
./build.sh
./install.sh
```

## 1.8.1

```bash
wget https://github.com/eosio/eosio.cdt/releases/download/v1.8.1/eosio.cdt_1.8.1-1-ubuntu-18.04_amd64.deb
apt install ./eosio.cdt_1.8.1-1-ubuntu-18.04_amd64.deb
```

- 源码安装方式

```bash
git clone --recursive https://github.com/eosio/eosio.cdt
cd eosio.cdt
mkdir build
cd build
cmake ..
make -j8
make install

#卸载
rm -fr /usr/local/eosio.cdt
rm -fr /usr/local/lib/cmake/eosio.cdt
rm /usr/local/bin/eosio-*
```