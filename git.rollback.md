# 回滚

## 1. 删除本地未暂存的文件

```bash
git clean -f
```

## 2. 取消暂存

```bash
git rm --cache file     #取消暂存文件但不删除
git rm --cache -r path  #取消暂存文件夹但不删除
```

## 3. 本地回滚某提交

### 3.1 回滚，本地文件也变为某次提交

```bash
git reset --hard <commit id>
```

- 可以用作取消暂存

```bash
git rm file             #从暂存区中删除单个文件或文件夹
```


### 3.2 回滚，本地文件始终保持当前提交，而非回滚后的提交

```bash
git reset --soft <commit id>	# --soft代表只删除提交记录，不删除本地文件
```

## 4. 远程回滚到某次提交

```bash
git reset --hard <commit id>
git push --force <commit id>
```


## 5. 删除所有的提交记录

```bash
git reset --soft <commit id>	# --soft代表只删除提交记录，不删除本地文件
								# <commit id> 修改为本分支的第一次提交的id
git push --force
git add . 
git commit -m "initial"
git push
```

