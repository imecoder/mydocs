# hardhat 项目中使用 deploy 插件

- [项目代码](hardhat.zip)

## 1. 生成`package.json`

```bash
npm init --yes
```

- `package.json` —— 除了配置依赖的开发包等一些信息，主要还能用来配置 `scripts` 字段，设置运行脚本。

## 2. 安装依赖

```bash
npm i --save-dev hardhat typescript hardhat-deploy hardhat-deploy-ethers ts-node
```

## 3. `hardhat.config.ts` 引入插件

```
vim hardhat.config.ts
```


```js
import 'hardhat-deploy';
import 'hardhat-deploy-ethers';
```

## 4. 写部署脚本

```bash
mkdir deploy
touch deploy/001_xxx.ts
touch deploy/002_yyy.ts

#运行时就是按照 001, 002, 003, ... 这种顺序执行的
```

- `001_xxx.ts`内容

```ts
//001_xxx.ts
import {HardhatRuntimeEnvironment} from 'hardhat/types';
import {DeployFunction} from 'hardhat-deploy/types';

const func: DeployFunction = async function (hre: HardhatRuntimeEnvironment) {
    console.log('这是只做了打印。001')
};
export default func;
```

- `002_yyy.ts`内容

```ts
//002_yyy.ts
import {HardhatRuntimeEnvironment} from 'hardhat/types';
import {DeployFunction} from 'hardhat-deploy/types';

const func: DeployFunction = async function (hre: HardhatRuntimeEnvironment) {
    console.log('这是只做了打印。002')
};
export default func;
```

## 5. 运行部署

```bash
npx hardhat deploy
```

![deploy.png](deploy.png)