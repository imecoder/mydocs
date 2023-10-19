# shadowsocks 服务器端配置

## 1. 启动

有两种启动方式，建议使用配置文件的方式启动

### 1.1 直接启动

```bash
ssserver -p 8388 -k password -m rc4-md5 -d start
```

- Ubuntu20.04上可能存在启动失败的情况，进行如下操作:

```bash
sed -i 's/cleanup/reset/g' /usr/local/lib/python3.8/dist-packages/shadowsocks/crypto/openssl.py
```


### 1.2 使用配置文件启动

执行 `vim /etc/shadowsocks.json` 添加如下内容：

#### 1.2.1 单用户配置

```json
{
    "server":"0.0.0.0",
    "server_port":8388,
    "local_address": "127.0.0.1",
    "local_port":1080,
    "password":"mypassword",
    "timeout":300,
    "method":"rc4-md5"
}
```

#### 1.2.2 多用户配置如下

```json
{  
 "server":"0.0.0.0"，  
 "local_address": "127.0.0.1",  
 "local_port":1080,  
  "port_password": {  
     "8388": "password",  
     "8387": "password",  
     "8386": "password",  
     "8385": "password"  
 },  
 "timeout":300,  
 "method":"rc4-md5",  
 "fast_open": false  
}
```

#### 1.2.3 启动

```bash
ssserver -c /etc/shadowsocks.json -d start
```

#### 1.2.4 停止

```bash
ssserver -c /etc/shadowsocks.json -d stop
```

> TIPS: 加密方式推荐使用rc4-md5，因为 RC4 比 AES 速度快好几倍，如果用在路由器上会带来显著性能提升。旧的 RC4 加密之所以不安全是因为 Shadowsocks 在每个连接上重复使用 key，没有使用 IV。现在已经重新正确实现，可以放心使用。更多可以看 issue。

## 2. 开机自启

创建文件 `/etc/supervisor/conf.d/shadowsocks.conf`

```ini
[program:shadowsocks]
command=ssserver -c /etc/shadowsocks.json
autostart=true
autorestart=true
user=root
log_stderr=true
logfile=/var/log/shadowsocks.log
```

```text
service supervisord start
supervisorctrl update
```

完成以上步骤后，重启之后，shadowsock会自动运行。