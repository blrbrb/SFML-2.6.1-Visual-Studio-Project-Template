# Visual Studio SFML 2.6.1 Project Template

[![N|Solid](https://www.sfml-dev.org/images/logo.png)](https://www.sfml-dev.org/index.php)

Here you will find some basic instructions on how to configure, and build this project template to suit your needs. Wether this is your very first project using C++ and sfml. Or if you're a seasoned professional looking for a lazy way to start testing a new idea. This project template uses the very latest release of SFML which has added among many other things, support for Vulkan surfaces 64-bits libraries for Android,  support for unity builds, and support for Visual Studio 2022. The Full changelog and list of features added in SFML 2.6.1 can be viewed on the offical [SFML changelog](https://www.sfml-dev.org/changelog.php#sfml-2.6.1)

## Setup

- Make sure [vcpkg](https://github.com/Microsoft/vcpkg) is installed on your machine / added to your path. You can find detailed instructions for the installation and configuration of vcpkg on Microsoft's offical github repository
- Clone this repository into a new empty directory
- (Optional) Open a new powershell, terminal, or command prompt window and run ``vcpkg install``. (this will automatically be done at complile time by Visual Studio)

### Naming Your Project

Open the solution explorer, right click the solution called "SFMLv2.6.1 Project Template" and retitle it to whatever you like.

Next, open vcpkg.json and apply the same name you gave the solution to the ```"name":""``` field at the very top of the file.

### Setting Up A Dynamically Linked Project

Building a static project means that SFML, and all of SFML's dependencies for the most part will be "bundeled" together into your project's executable. By default, the Visual Studio solution is set to ```/Multi-threaded Debug (/MTd)``` when building the project's _debug_ configuration, and ```/Multi-threaded (/MT)``` when building the project's _release_ configuration.

Setting your project up to use _dynamic_ libraries instead of statically linked ones is as easy as right-clicking on the solution in visual studio, and navigating to the "C++" drop-down menu. To configure your project to use dynamically linked (.dll) libraries complete the following steps:

- Right click your project's solution in the solution explorer, navigate to __Code Generation__ inside of __C++__
- Next to the option called __Runtime Library__ erase the default value. ```/Multi-threaded Debug (/MTd)``` for debug and ```Multi-threaded (/MT)``` for release.
- Navigate to __PreProcessor__ inside of __C++__. At the very top of the page you will find an option called __Preprocessor Definitions__. Remove the the portion that says "__SFML_STATIC__". This will ensure that when you build your project, SFML knows not to link against static libraries, and instead Visual Studio will place the .dlls alongside your project's executable.
- Under __vcpkg__, set the option called __Use Static Libraries__ to false. Change the value under __Host Triplet__ from __x64-windows-static__ to __x64-windows__.

## Common Issues and Solutions

Some of the most common reasons builds have failed for me in the past, and solutions I've found.

- If you're building a static project, and you run into an issue involving undefined external symbols in sfml-main-s.lib. Make sure that __winnm.lib__ is included in the __Additional Dependencies__ option under __Linker/Input__.
