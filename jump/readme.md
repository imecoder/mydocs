# jump

wireguard+shadowsocks+nginx组合可以成为绝佳的jump工具。

- 基本需求

1. 外服与内服之间要通过 wireguard 实现局域网连接，进而进行数据转发，可以有效的防止被封。
2. 外服用于破墙，配置shadowsocks服务端。
3. 内服用于转发，通过nginx进行低层数据转发。
4. 终端配置shadowsocks客户端，直接访问内服。


- [wireguard](wireguard/readme.md)
- [shadowsocks](shadowsocks/readme.md)
- [nginx](nginx.readme.md)