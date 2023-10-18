# vscode 美化

安装主题 "Atom One Light", "material-icon-theme"

"Ctrl+shift+p" -> "Open Settings"

修改 settings.json 文件内容如下：

```json
{
    "terminal.external.windowsExec": "C:\\Program Files\\Git\\git-bash.exe",
    "terminal.integrated.defaultProfile.windows": "Git Bash",
    "workbench.colorTheme": "Atom One Light",
    "workbench.iconTheme": "material-icon-theme",
    "explorer.confirmDelete": false,
    "workbench.startupEditor": "none",
    "editor.fontFamily": "'Fira Code', Consolas, 'Courier New', monospace",
    "editor.fontLigatures": true,
    "workbench.editor.enablePreview": false,
    "editor.insertSpaces": false,
    "security.workspace.trust.untrustedFiles": "open",
    "editor.detectIndentation": true,
    "json.maxItemsComputed": 100000,
    "workbench.colorCustomizations": {
    "[Atom One Light]": {
        "editor.background": "#c9f4e9",   
        "sideBar.background": "#d5efff",
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
    "editor.fontWeight": "450",
    "workbench.sideBar.location": "right",
    "window.openFilesInNewWindow": "on",
    "[json]": {
        "editor.defaultFormatter": "vscode.json-language-features"
    }
}
```