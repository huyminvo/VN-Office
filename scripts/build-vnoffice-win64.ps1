param(
    [string]$Version = "9.4.0.0",
    [string]$Arch = "x64",
    [string]$InnoPath = "",
    [switch]$SkipRuntimeBuild,
    [switch]$SkipInstallerBuild
)

$ErrorActionPreference = "Stop"

$RepoRoot = Split-Path -Parent $PSScriptRoot
$BuildTools = Join-Path $RepoRoot "build_tools"
$PackageDir = Join-Path $RepoRoot "desktop-apps\package"
$RuntimeDir = Join-Path $BuildTools "out\win_64\onlyoffice\DesktopEditors"

if (-not $SkipRuntimeBuild) {
    Push-Location $BuildTools
    try {
        python make.py
    }
    finally {
        Pop-Location
    }
}

if (-not (Test-Path -LiteralPath $RuntimeDir)) {
    throw "Runtime output not found: $RuntimeDir"
}

powershell -NoProfile -ExecutionPolicy Bypass -File (Join-Path $PackageDir "make.ps1") `
    -Version $Version `
    -Arch $Arch `
    -Target "opensource" `
    -CompanyName "VN Office" `
    -ProductName "DesktopEditors" `
    -SourceDir $RuntimeDir

if (-not $SkipInstallerBuild) {
    if ($InnoPath) {
        $env:INNOPATH = $InnoPath
    }

    powershell -NoProfile -ExecutionPolicy Bypass -File (Join-Path $PackageDir "make_inno.ps1") `
        -Version $Version `
        -Arch $Arch `
        -Target "opensource" `
        -CompanyName "VN Office" `
        -ProductName "DesktopEditors"
}

$Installer = Join-Path $PackageDir "inno\VN Office-DesktopEditors-$Version-$Arch.exe"
if (Test-Path -LiteralPath $Installer) {
    Get-Item -LiteralPath $Installer
}
