# 鼠标右键菜单定制

安装路径中 => menu.reg

具体软件，替换可执行文件名

双击运行

```bat
@echo Off
:START
CLS
echo *=========================================================================*
echo *         UEStudio 安装完成后没有右键打开方式，打开文件很不方便。       *
echo * 为了方便快捷打开文件，可以通过以下A选项添加右键菜单 UEStudio 打开方式 *
echo *                                                                         *
echo *       注意: 该bat文件必须和安装后的 UEStudio.exe 在同级目录           *
echo *                            [A]添加右键菜单                              *
echo *                            [D]删除右键菜单                              *
echo *                            [Q]退出                                      *
echo *                                                                         *
echo *                           爱前端：www.webqianduan.cn                    *
echo *=========================================================================*
Set /P Choice=　　　　　　　请选择要进行的操作 (A/D/Q) ，然后按回车：
If /I "%Choice%"=="A" Goto :ADD
If /I "%Choice%"=="D" Goto :DEL
If /I "%Choice%"=="Q" Exit

START

:ADD
CLS
set str=%cd%

echo Windows Registry Editor Version 5.00> tmp.reg
echo [HKEY_CLASSES_ROOT\*\shell]>> tmp.reg
echo [HKEY_CLASSES_ROOT\*\shell\UEStudio]>> tmp.reg
echo @="通过 UEStudio 打开">> tmp.reg
echo "Icon"="\"%str:\=\\%\\UEStudio.exe\",0">> tmp.reg
echo [HKEY_CLASSES_ROOT\*\shell\UEStudio\Command]>> tmp.reg
echo @="\"%str:\=\\%\\UEStudio.exe\" \"%%1^\"">> tmp.reg

echo Windows Registry Editor Version 5.00>> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\shell]>> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\shell\UEStudio]>> tmp.reg
echo @="通过 UEStudio 打开文件夹">> tmp.reg
echo "Icon"="\"%str:\=\\%\\UEStudio.exe\",0">> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\shell\UEStudio\Command]>> tmp.reg
echo @="\"%str:\=\\%\\UEStudio.exe\" \"%%1^\"">> tmp.reg

echo Windows Registry Editor Version 5.00>> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\Background\shell]>> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\Background\shell\UEStudio]>> tmp.reg
echo @="通过 UEStudio 打开文件夹">> tmp.reg
echo "Icon"="\"%str:\=\\%\\UEStudio.exe\",0">> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\Background\shell\UEStudio\Command]>> tmp.reg
echo @="\"%str:\=\\%\\UEStudio.exe\" \"%%V^\"">> tmp.reg


echo *=========================================================================*
echo *                                                                         *
echo *   正在将生成的注册信息写入注册表，请点击“是”键钮！                      *
echo *                                                                         *
echo *=========================================================================*
tmp.reg
del tmp.reg
GOTO :START

:DEL
echo Windows Registry Editor Version 5.00> tmp.reg
echo [-HKEY_CLASSES_ROOT\*\shell\UEStudio]>> tmp.reg
echo [-HKEY_CLASSES_ROOT\Directory\shell\UEStudio]>> tmp.reg
echo [-HKEY_CLASSES_ROOT\Directory\Background\shell\UEStudio]>> tmp.reg
tmp.reg
del tmp.reg
GOTO :START
```