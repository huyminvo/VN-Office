# VN Office

VN Office is a Windows desktop office suite build assembled from the modified source tree in this repository.

Project links:

- Repository: https://github.com/huyminvo/VN-Office
- Author: HuyMin
- Email: nvminhhuy2202@gmail.com
- Author website: https://www.facebook.com/huymin222/

## What is included

- `desktop-apps` - Windows/Linux desktop shell, installer scripts, VN Office branding assets, icons, About/update metadata.
- `web-apps` - editor UI/web assets and VN Office theme metadata.
- `build_tools` - build orchestration scripts. VN Office update/help links point to `huyminvo/VN-Office`.
- `core`, `sdkjs`, `desktop-sdk`, `dictionaries`, `core-fonts`, `document-templates` - source modules required by the Windows build.
- `docs/BUILD-WINDOWS.md` - exact Windows build workflow used for the successful local build.
- `scripts/build-vnoffice-win64.ps1` - wrapper script for runtime build and Inno installer packaging.

Use Git LFS when cloning this repository because selected build dependencies are stored through LFS.

```powershell
git lfs install
git clone https://github.com/huyminvo/VN-Office.git
```

The generated installer is intentionally not committed because GitHub blocks files over 100 MB. The last verified local installer was:

`D:\CANHAN\SOURCE WARP\VN-Office-DesktopEditors-9.4.0.0-x64-rebrand-fixed.exe`

## Branding state

The Windows runtime and package metadata are branded as:

- Product: `VN Office`
- Author/company: `HuyMin`
- Update channel: `https://github.com/huyminvo/VN-Office/releases/latest/download/appcast.json`
- Help URL: `https://github.com/huyminvo/VN-Office/releases/download/help-v9.4.0/apps`
- Main AppUserModelID: `HuyMin.VNOffice.1`

## License

VN Office custom branding/build changes are provided under the MIT License in `LICENSE`.

Third-party components and bundled upstream modules may retain their own license terms. Keep their notices and license files when redistributing builds.
