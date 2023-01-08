# ImProject

A template project to begin ImGui-based application with GLFW backend on Linux.

If you are looking for a more featured swiss knife try https://github.com/pthom/hello_imgui .

## How to use
- If you have a GitHub account just press  "Use this template" button.
- Clone and don't forget to init submodules.
- Place your code in the "src/" folder.
- Create your own root application class, which inherits ImApplication.

For example this application [ImOsmDemo](https://github.com/gorbatschow/ImOsmWidgetDemo) is based on ImProject template.

## What's in the box
The following external dependencies are included as submodules
- GLFW https://github.com/glfw/glfw
- ImGui https://github.com/ocornut/imgui
- ImPlot https://github.com/epezent/implot
- STB https://github.com/nothings/stb
- mINI https://github.com/pulzed/mINI

Also included small libraries made by me
- ImApplication https://github.com/gorbatschow/ImApplication
- ImFonts https://github.com/gorbatschow/ImFonts
- ImWrapper https://github.com/gorbatschow/ImWrapper

## Ubuntu/Mint dependencies
The following packages must be installed
```
libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev freeglut3-dev
```
and maybe others...

## Other operating systems
Try and tell me :)
