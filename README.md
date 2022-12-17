# ImProject

A template project to easily start with ImGui with GLFW backend on Linux.

If you are looking for a more featured swiss knife try https://github.com/pthom/hello_imgui .

## How to use
- If you have a GitHub account just press  "Use this template" button.
- Clone and don't forget to init submodules.
- Place your code in the "src/" folder.
- Create your own root application class, which inherits ImApplication.

For example this application ![ImOsmDemo](https://github.com/gorbatschow/ImOsmWidgetDemo) is based on ImProject template.

## What's is in the box
The following external dependencies are included as submodules
- GLFW https://github.com/glfw/glfw
- ImGui https://github.com/ocornut/imgui
- ImPlot https://github.com/epezent/implot
- STB https://github.com/nothings/stb

Also included tiny libraries made by me
- ImApplication https://github.com/gorbatschow/ImApplication
- ImFonts https://github.com/gorbatschow/ImFonts
 
## Ubuntu/Mint dependencies
Probably you have to install the following packages
```
sudo apt install libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev freeglut3-dev
```
and maybe others...

## Other operating systems
Try and tell me :)
