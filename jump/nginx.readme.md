# nginx 底层数据转发配置

`vim /etc/nginx/nginx.conf`

- 添加如下内容

```bash

stream {
	server {
		listen 58388;
		proxy_pass 172.17.xx.xx:58388;
	}
}

```

> 172.17.50.7为外服的内网ip，需要使用wireguard配通与内服的连通。