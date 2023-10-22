# eosio 2.1 编译安装

## 下载eosio源码仓库

```bash
# set EOSIO directories
export EOSIO_LOCATION=~/eosio/eos
export EOSIO_INSTALL_LOCATION=$EOSIO_LOCATION/../install
mkdir -p $EOSIO_INSTALL_LOCATION
# install git
apt-get update && apt-get install -y git
# clone EOSIO repository
git clone https://github.com/EOSIO/eos.git $EOSIO_LOCATION
cd $EOSIO_LOCATION && git submodule update --init --recursive
```

## 安装依赖

### 安装依赖库
```bash
apt-get install -y make bzip2 automake libbz2-dev libssl-dev doxygen graphviz libgmp3-dev  autotools-dev python2.7 python2.7-dev python3 python3-dev autoconf libtool curl zlib1g-dev ruby libusb-1.0-0-dev libcurl4-gnutls-dev pkg-config patch llvm-7-dev clang-7 vim-common jq
```

### 构建 cmake
```bash
export PATH=$EOSIO_INSTALL_LOCATION/bin:$PATH
cd $EOSIO_INSTALL_LOCATION && curl -LO https://cmake.org/files/v3.13/cmake-3.13.2.tar.gz && \
    tar -xzf cmake-3.13.2.tar.gz && \
    cd cmake-3.13.2 && \
    ./bootstrap --prefix=$EOSIO_INSTALL_LOCATION/cmake && \
    make -j$(nproc) && \
    make install && \
    rm -rf $EOSIO_INSTALL_LOCATION/cmake-3.13.2.tar.gz $EOSIO_INSTALL_LOCATION/cmake-3.13.2
```

### 构建 boost
```bash
cd $EOSIO_INSTALL_LOCATION && curl -LO https://boostorg.jfrog.io/artifactory/main/release/1.71.0/source/boost_1_71_0.tar.bz2 && \
    tar -xjf boost_1_71_0.tar.bz2 && \
    cd boost_1_71_0 && \
    ./bootstrap.sh --prefix=$EOSIO_INSTALL_LOCATION/boost && \
    ./b2 --with-iostreams --with-date_time --with-filesystem --with-system --with-program_options --with-chrono --with-test -q -j$(nproc) install && \
    rm -rf $EOSIO_INSTALL_LOCATION/boost_1_71_0.tar.bz2 $EOSIO_INSTALL_LOCATION/boost_1_71_0
```

## 

## 构建eosio

```bash
export EOSIO_BUILD_LOCATION=$EOSIO_LOCATION/build
mkdir -p $EOSIO_BUILD_LOCATION
cd $EOSIO_BUILD_LOCATION && cmake -DCMAKE_BUILD_TYPE='Release' -DCMAKE_CXX_COMPILER='clang++-7' -DCMAKE_C_COMPILER='clang-7' -DLLVM_DIR='/usr/lib/llvm-7/lib/cmake/llvm' -DCMAKE_INSTALL_PREFIX=$EOSIO_INSTALL_LOCATION $EOSIO_LOCATION
cd $EOSIO_BUILD_LOCATION && make -j$(nproc)
```

## 

## 安装eosio

```bash
cd $EOSIO_BUILD_LOCATION && make install
```

## 

## 构建eosio test

```bash
cd $EOSIO_BUILD_LOCATION && make test
```

## 

## 卸载eosio

```bash
xargs rm < $EOSIO_BUILD_LOCATION/install_manifest.txt
rm -rf $EOSIO_BUILD_LOCATION
```

