# vscode 美化

安装主题 "Atom One Light", 在此主题上继续更改

"Ctrl+shift+p" -> "Open Settings"

修改 settings.json 文件内容如下：

```json
{
	"explorer.confirmDelete": false,
    "workbench.startupEditor": "none",
    "editor.fontFamily": "'Fira Code', Consolas, 'Courier New', monospace",
    "editor.fontLigatures": true,
    "workbench.iconTheme": "material-icon-theme",
    "workbench.editor.enablePreview": false,
    "editor.insertSpaces": false,
    "security.workspace.trust.untrustedFiles": "open",
	"editor.detectIndentation": true,
	"json.maxItemsComputed": 100000,
	"workbench.colorTheme": "Atom One Light",
    "workbench.colorCustomizations": {
    "[Atom One Light]": {
        "editor.background": "#d5efff",   
        "sideBar.background": "#c9f4e9",
		"sideBar.border": "#ff0000",
		"statusBar.background": "#009dffb5",
        "activityBar.background": "#ebd5e8", 
		"titleBar.activeBackground": "#009dffb5",
		"titleBar.activeForeground": "#ffffff",
		"menu.background": "#1d94ddb5",
		"menu.foreground": "#ffffff",
		"minimap.foregroundOpacity": "#ff0000"
        },
	},
	"terminal.integrated.profiles.windows": {
		"PowerShell": {
			"source": "PowerShell",
			"icon": "terminal-powershell"
		},
		"Command Prompt": {
			"path": [
				"${env:windir}\\Sysnative\\cmd.exe",
				"${env:windir}\\System32\\cmd.exe"
			],
			"args": [],
			"icon": "terminal-cmd"
		},
		"bash": {
			"path": "C:\\msys64\\bin\\bash.exe"
		},
		"Windows PowerShell": {
			"path": "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"
		}
	},
	"terminal.integrated.defaultProfile.windows": "bash",
	"editor.fontWeight": "450",
	"workbench.sideBar.location": "right",
	"window.openFilesInNewWindow": "on",
	"[json]": {
		"editor.defaultFormatter": "vscode.json-language-features"
	}
}
```