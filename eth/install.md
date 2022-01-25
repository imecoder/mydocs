# Ubuntu 16.04 快速搭建以太坊私有链及转账测试



## 1. golang安装

```bash
wget https://studygolang.com/dl/golang/go1.11.linux-amd64.tar.gz

tar xzvf go1.11.linux-amd64.tar.gz -C /opt

echo >> ~/.bashrc
echo 'export GOPATH=/opt/gopath' >> ~/.bashrc
echo 'export GOROOT=/opt/go' >> ~/.bashrc
echo '#export GOARCH=amd64' >> ~/.bashrc
echo '#export GOOS=linux' >> ~/.bashrc
echo 'export GOTOOLS=$GOROOT/pkg/tool' >> ~/.bashrc
echo 'export PATH=$PATH:$GOROOT/bin:$GOPATH/bin' >> ~/.bashrc

source ~/.bashrc
```

## 2.安装以太坊客户端Ethereum

```bash
apt-get install software-properties-common
add-apt-repository -y ppa:ethereum/ethereum
apt-get update
apt-get install ethereum

geth version
  Geth Version: 1.8.11-stable
```

## 3. 以太坊私有链搭建

### 3.1 创建创世文件

```bash
vim genesis.json
```

```json
{
  "config": {
    "chainId": 666,
    "homesteadBlock": 0,
    "eip150Block": 0,
    "eip150Hash": "0x0000000000000000000000000000000000000000000000000000000000000000",
    "eip155Block": 0,
    "eip158Block": 0,
    "byzantiumBlock": 0,
    "constantinopleBlock": 0,
    "petersburgBlock": 0,
    "istanbulBlock": 0,
    "ethash": {}
  },
  "nonce": "0x0",
  "timestamp": "0x5ddf8f3e",
  "extraData": "0x0000000000000000000000000000000000000000000000000000000000000000",
  "gasLimit": "0x47b760",
  "difficulty": "0x00002",
  "mixHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
  "coinbase": "0x0000000000000000000000000000000000000000",
  "alloc": { },
  "number": "0x0",
  "gasUsed": "0x0",
  "parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000"
}
```

### 3.2 初始化创世区块，并指定数据存放路径

```bash
geth --datadir data0 init genesis.json
```

### 3.3 启动私有链节点，并将日志输入到data0.log

```bash
geth --networkid 666 --datadir data0 --identity "data0" --rpc --rpcaddr 0.0.0.0 --rpcport 8545 --rpcapi "admin,debug,eth,miner,net,personal,shh,txpool,web3" --port 30303 --rpccorsdomain "*" --nodiscover --allow-insecure-unlock console 2>>data0.log
```

启动成功后进入控制台界面，如下所示:

```txt
Welcome to the Geth JavaScript console!

instance: Geth/data0/v1.8.11-stable-dea1ce05/linux-amd64/go1.10
 modules: admin:1.0 debug:1.0 eth:1.0 miner:1.0 net:1.0 personal:1.0 rpc:1.0 txpool:1.0 web3:1.0

>
```

至此，ubuntu 16.04 下以太坊私有链环境已经搭好，接下在进行简单测试。

## 4.测试

### 4.1 创建新账户

```bash
personl.newAccount("密码")
```

创建成功将返回账户的地址

```bash
> personal.newAccount("111111")
> "0xe6319357003ff9889b7a849f5ec66b2903d08289" 
```

### 4.2 查询账户余额

```bash
eth.getBalance("账户地址")
```

由于新建账户，没有余额，所以查询的结果为 0

```bash
> eth.getBalance("0xe6319357003ff9889b7a849f5ec66b2903d08289")
> 0
```

### 4.3 开启/停止挖矿，第一次开起需要等待一段时间。

```bash
> miner.start()
> miner.stop()
```

查看挖矿日志，可以新开启一个终端，输入下面命令进行查看

```bash
tail -f data0.log
```

### 4.4 转账

挖矿成功后，默认会将以太币给第一个账户，查看余额

```bash
> eth.getBalance(eth.accounts[0])
> 135000000000000000000
```

> eth.accounts：以数组形式返回为账户列表，当前只有一个账户，可用eth.accounts[0]表示

### 4.5 新建一个账户，查看余额

```bash
> personal.newAccount("222222")
> "0x866e46b71923d54e6fee26f42ececc216ca76c1d"
> eth.getBalance(eth.accounts[1])
> 0
```

### 4.6 从accounts[0]向accounts[1]发送1个以太币，首先需要解锁accounts[0]，使用如下命令

```bash
> personal.unlockAccount(eth.accounts[0],"111111",0)
> true
```

> 三个参数分别为accounts[0]的地址，创建时的密码及解锁时间（毫秒为单位）。0 代表长时间解锁

### 4.7 转账操作

```bash
> eth.sendTransaction({from:eth.accounts[0],to:eth.accounts[1],value:web3.toWei(1,'ether')})
```
> 开启挖矿等待区块验证，转账成功后，查询accounts[1]余额，默认单位是Wei

```bash
> eth.getBalance(eth.accounts[1])
> 100000000000000000
```

> 可以使用web3.fromWei()命令将wei转为ether。

 
