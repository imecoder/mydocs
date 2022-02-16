# hardhat 项目基础环境构建

## 1. 生成`package.json`

```bash
npm init --yes
```

- `package.json` —— 除了配置依赖的开发包等一些信息，主要还能用来配置 `scripts` 字段，设置运行脚本。

## 2. 生成项目

```bash
npm i --save-dev hardhat
npx hardhat
```

```txt
888    888                      888 888               888
888    888                      888 888               888
888    888                      888 888               888
8888888888  8888b.  888d888 .d88888 88888b.   8888b.  888888
888    888     "88b 888P"  d88" 888 888 "88b     "88b 888
888    888 .d888888 888    888  888 888  888 .d888888 888
888    888 888  888 888    Y88b 888 888  888 888  888 Y88b.
888    888 "Y888888 888     "Y88888 888  888 "Y888888  "Y888

Welcome to Hardhat v2.8.4

? What do you want to do? ...
  Create a basic sample project
  Create an advanced sample project
> Create an advanced sample project that uses TypeScript	#此处是创建一个比较完备的项目
  Create an empty hardhat.config.js
  Quit
```

选择 `Create an advanced sample project that uses TypeScript` 后，会创建一个十分完备的 typescript 的hardhat项目， 会创建出 `hardhat.config.ts`、`tsconfig.json`、`contracts`、`test`、`script`等等目录和文件。

- `tsconfig.json` —— 主要是用来控制ts编译到js的选项
- `hardhat.config.ts`——主要是用来配置task, 和 配置部署环境。

## 3. 安装项目依赖

```bash
npm i --save-dev hardhat @nomiclabs/hardhat-waffle ethereum-waffl
e chai @nomiclabs/hardhat-ethers ethers @nomiclabs/hardhat-etherscan dotenv eslint eslint-config-prettier eslint-conf
ig-standard eslint-plugin-import eslint-plugin-node eslint-plugin-prettier eslint-plugin-promise hardhat-gas-reporter
 prettier prettier-plugin-solidity solhint solidity-coverage @typechain/ethers-v5 @typechain/hardhat @typescript-esli
nt/eslint-plugin @typescript-eslint/parser @types/chai @types/node @types/mocha ts-node typechain typescript
```

## 4. 配置 `hardhat-deploy` 插件

这个插件主要用来批量部署。

```bash
npm i --save-dev hardhat-deploy hardhat-deploy-ethers
```

## 5. `hardhat.config.ts` 引入插件

```js
import 'hardhat-deploy';
import 'hardhat-deploy-ethers';
```

## 6. 写部署脚本

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

## 7. 运行部署

```bash
npx hardhat deploy
```

![deploy.png](deploy.png)