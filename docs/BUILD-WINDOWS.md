# Build VN Office for Windows

This guide documents the workflow used to build the verified Windows installer.

## Tested build

- Product: VN Office Desktop Editors
- Version: 9.4.0.0
- Platform: Windows x64
- Installer output: `desktop-apps\package\inno\VN Office-DesktopEditors-9.4.0.0-x64.exe`

## Required tools

- Windows 10/11 x64
- Visual Studio Build Tools 2022 with C++ workload
- Python 3.12 or compatible Python 3
- Node.js
- Git and Git LFS
- Qt 5.15.2 MSVC x64
- Inno Setup 6
- PowerShell 5+

Before cloning, enable Git LFS:

```powershell
git lfs install
git clone https://github.com/huyminvo/VN-Office.git
```

The local successful build used:

- Qt path: `D:\CANHAN\Qt\5.15.2`
- Inno Setup path: `D:\CANHAN\SOURCEWARP_BUILD\tools\InnoSetup`
- Visual Studio tools: `C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools`

Adjust `build_tools\config` if your Qt or Visual Studio path is different.

## Build runtime

From the repository root:

```powershell
cd build_tools
python make.py
```

Expected runtime output:

```text
build_tools\out\win_64\onlyoffice\DesktopEditors
```

Important VN Office values are injected by `build_tools\make.py`:

- Main update appcast: `https://github.com/huyminvo/VN-Office/releases/latest/download/appcast.json`
- Dev update appcast: `https://github.com/huyminvo/VN-Office/releases/latest/download/appcast-dev.json`
- Help URL: `https://github.com/huyminvo/VN-Office/releases/download/help-v9.4.0/apps`

## Package installer

Prepare package payload:

```powershell
$pkg = "desktop-apps\package"
$src = "build_tools\out\win_64\onlyoffice\DesktopEditors"
powershell -NoProfile -ExecutionPolicy Bypass -File "$pkg\make.ps1" `
  -Version "9.4.0.0" `
  -Arch "x64" `
  -Target "opensource" `
  -CompanyName "VN Office" `
  -ProductName "DesktopEditors" `
  -SourceDir $src
```

Build Inno installer:

```powershell
$env:INNOPATH = "C:\Program Files (x86)\Inno Setup 6"
$pkg = "desktop-apps\package"
powershell -NoProfile -ExecutionPolicy Bypass -File "$pkg\make_inno.ps1" `
  -Version "9.4.0.0" `
  -Arch "x64" `
  -Target "opensource" `
  -CompanyName "VN Office" `
  -ProductName "DesktopEditors"
```

If using the bundled local Inno directory from the previous build machine, set:

```powershell
$env:INNOPATH = "D:\CANHAN\SOURCEWARP_BUILD\tools\InnoSetup"
```

## One-command wrapper

You can also run:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\build-vnoffice-win64.ps1
```

Optional parameters:

```powershell
.\scripts\build-vnoffice-win64.ps1 -Version "9.4.0.0" -InnoPath "C:\Program Files (x86)\Inno Setup 6"
```

## Verification checklist

After build, verify:

```powershell
$desktop = "desktop-apps\package\build\x64\desktop"
Get-Item "$desktop\DesktopEditors.exe", "$desktop\editors.exe", "$desktop\updatesvc.exe" |
  Select-Object Name, @{n="ProductName";e={$_.VersionInfo.ProductName}}, @{n="CompanyName";e={$_.VersionInfo.CompanyName}}, @{n="FileDescription";e={$_.VersionInfo.FileDescription}}
```

Expected:

- `DesktopEditors.exe` product: `VN Office Editors`
- `editors.exe` product: `VN Office`
- `updatesvc.exe` product: `VN Office Update Service`
- company: `HuyMin`

Check old visible branding strings:

```powershell
$desktop = "desktop-apps\package\build\x64\desktop"
foreach ($p in @(
  "Euro-Office",
  "Euro Office",
  "EuroOffice",
  "github.com/euro-office",
  "github.com/Euro-Office",
  "templates.onlyoffice.com",
  "download.onlyoffice.com/install/desktop/editors/windows/onlyoffice",
  "ASC.Documents.5"
)) {
  $hits = rg -l -a -S --fixed-strings $p $desktop --max-filesize 20M 2>$null
  if ($hits) { "--- $p"; $hits }
}
```

## Smoke test

```powershell
$exe = "desktop-apps\package\build\x64\desktop\editors.exe"
$p = Start-Process -FilePath $exe -WorkingDirectory (Split-Path $exe) -PassThru
Start-Sleep -Seconds 15
Get-Process | Where-Object { $_.ProcessName -match "DesktopEditors|editors|editors_helper" } |
  Select-Object Id, ProcessName, MainWindowTitle, Responding
```

The main window title should be `VN Office`.
