@echo Off
:START
CLS
echo *=========================================================================*
echo *         UEStudio ��װ��ɺ�û���Ҽ��򿪷�ʽ�����ļ��ܲ����㡣       *
echo * Ϊ�˷����ݴ��ļ�������ͨ������Aѡ������Ҽ��˵� UEStudio �򿪷�ʽ *
echo *                                                                         *
echo *       ע��: ��bat�ļ�����Ͱ�װ��� UEStudio.exe ��ͬ��Ŀ¼           *
echo *                            [A]����Ҽ��˵�                              *
echo *                            [D]ɾ���Ҽ��˵�                              *
echo *                            [Q]�˳�                                      *
echo *                                                                         *
echo *                           ��ǰ�ˣ�www.webqianduan.cn                    *
echo *=========================================================================*
Set /P Choice=����������������ѡ��Ҫ���еĲ��� (A/D/Q) ��Ȼ�󰴻س���
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
echo @="ͨ�� UEStudio ��">> tmp.reg
echo "Icon"="\"%str:\=\\%\\UEStudio.exe\",0">> tmp.reg
echo [HKEY_CLASSES_ROOT\*\shell\UEStudio\Command]>> tmp.reg
echo @="\"%str:\=\\%\\UEStudio.exe\" \"%%1^\"">> tmp.reg

echo Windows Registry Editor Version 5.00>> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\shell]>> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\shell\UEStudio]>> tmp.reg
echo @="ͨ�� UEStudio ���ļ���">> tmp.reg
echo "Icon"="\"%str:\=\\%\\UEStudio.exe\",0">> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\shell\UEStudio\Command]>> tmp.reg
echo @="\"%str:\=\\%\\UEStudio.exe\" \"%%1^\"">> tmp.reg

echo Windows Registry Editor Version 5.00>> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\Background\shell]>> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\Background\shell\UEStudio]>> tmp.reg
echo @="ͨ�� UEStudio ���ļ���">> tmp.reg
echo "Icon"="\"%str:\=\\%\\UEStudio.exe\",0">> tmp.reg
echo [HKEY_CLASSES_ROOT\Directory\Background\shell\UEStudio\Command]>> tmp.reg
echo @="\"%str:\=\\%\\UEStudio.exe\" \"%%V^\"">> tmp.reg


echo *=========================================================================*
echo *                                                                         *
echo *   ���ڽ����ɵ�ע����Ϣд��ע����������ǡ���ť��                      *
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