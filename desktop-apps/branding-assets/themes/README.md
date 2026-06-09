# VN Office Theme Tokens

VN Office uses a techno visual direction that is separate from VN Office and
ONLYOFFICE.

Theme modes:

- `light`: bright productivity theme with red/yellow VN identity and cyan tech accents.
- `dark`: low-glare dark theme with cyan highlights and red/yellow brand anchors.
- `system`: follows the operating system preference when the VCL platform backend exposes it.

Module display names:

- Writer -> Word
- Calc -> Excel
- Impress -> PowerPoint
- Draw -> Diagrams
- Base -> Access
- Math -> Formula

These names are used as familiar compatibility labels. Microsoft Word,
Microsoft Excel, Microsoft PowerPoint, Microsoft Access, and Microsoft Office
are trademarks of Microsoft. VN Office is not affiliated with or endorsed by
Microsoft.

Primary integration targets in Apache OpenOffice:

- `main/vcl/*`: platform `StyleSettings` bridge for window, menu, field, highlight, and toolbar colors.
- `main/officecfg/registry/schema/org/openoffice/Office/UI.xcs`: persisted UI color scheme settings.
- `main/officecfg/registry/schema/org/openoffice/Office/ExtendedColorScheme.xcs`: document/editor color schemes.
- `main/sfx2/source/sidebar/Theme.*`: sidebar and panel colors.
- `main/default_images/introabout/`: startup/about visuals.

Rules:

- Do not import VN Office or ONLYOFFICE UI assets.
- Keep Apache License and attribution files intact.
- Treat theme token names as stable API for future C++ integration.
