# 安装gitlab

- 普通安装模式
```bash
apt-get install curl openssh-server ca-certificates postfix

#这一步打开代理
curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash

# script.deb.sh 此文件已经下载
apt-get install gitlab-ce
dpkg -i gitlab-ce-XXX.deb
gitlab-ctl reconfigure
```

> `script.deb.sh` 此文件已经下载

- [gitlab docker 安装 - https://docs.gitlab.cn/jh/install/docker.html](https://docs.gitlab.cn/jh/install/docker.html)


```bash
mkdir -p /data/gitlab
export GITLAB_HOME=/data/gitlab

docker run --detach \
  --hostname localhost \
  --publish 443:443 --publish 80:80 --publish 22:22 \
  --name gitlab \
  --restart always \
  --volume $GITLAB_HOME/config:/etc/gitlab \
  --volume $GITLAB_HOME/logs:/var/log/gitlab \
  --volume $GITLAB_HOME/data:/var/opt/gitlab \
  --shm-size 256m \
  gitlab-jh.tencentcloudcr.com/omnibus/gitlab-jh:latest
```