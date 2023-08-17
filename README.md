<table border="0">
  <tr>
    <td align="left" valign="middle">
    <h1>EFR32 Zephyr Application Examples</h1>
  </td>
  <td align="left" valign="middle">
    <a href="https://www.silabs.com/wireless/bluetooth">
      <img src="http://pages.silabs.com/rs/634-SLU-379/images/WGX-transparent.png"  title="Silicon Labs Wireless Gecko MCUs" alt="EFM32 32-bit Microcontrollers" width="250"/>
    </a>
  </td>
  </tr>
</table>

# Silicon Labs Zephyr Applications #

[![Version Badge](https://img.shields.io/badge/-v1.0.0-green)](https://github.com/SiliconLabs/zephyr_applications/releases)
![License badge](https://img.shields.io/badge/License-Zlib-green)

This repository contains example projects that demonstrate various applications running on Zephyr OS supported on Silicon Labs Development Kits.
All examples in this repository are considered to be EXPERIMENTAL QUALITY, which implies that the code provided in the repository has not been formally tested and is provided as-is. It is not suitable for production environments.

## Examples ##

| No | Example name | Link to example |
|:--:|:-------------|:---------------:|
|  1 |Zephyr - MikroBus Demo | [Click Here](./zephyr_mikrobus_demo/)|
|  2 |Zephyr - Si7210 Hall Effect Magnetic Sensor | [Click Here](./zephyr_si7210_onboard_led/)|


## Setting up environment ##

For setting up the Zephyr environment, please follow some steps below:

- Select and update OS.

- Install some host dependencies using your package manager.

  | Tool | Min. Version |
  |:--:|:---------------:|
  |  [Cmake](https://cmake.org/) | 3.20.5 |
  |  [Python](https://www.python.org/) | 3.8 |
  |  [Devicetree complier](https://www.devicetree.org/) | 1.4.6 |

- Get Zephyr and install Python dependencies.

- Install Zephyr SDK.

**Note:**

- For more information regarding setting up the environment, please refer to [this guide] on Zephyr's homepage(https://docs.zephyrproject.org/latest/develop/getting_started/index.html).

- We would advise using the Python version between 3.8 and 3.10.


## How to make your own application ##

The following guides are relevant to how to be more familiar with Zephyr OS and make a simple application.

### Getting started with basic examples ###

You can start with a variety of examples in the `zephyrproject/zephyr/sample` directory. It might be best to approach Zephyr and understand how Zephyr works.

The typical example outline as below:

```txt
  +--boards                       > Contains devicetree overlay files for each supported boards.
  +--build                        > Contains the binary and system files of the example.
  +--src                          > Contains source code files of the example.
  +--CmakeLists.txt               > Contains a set of directives and instructions describing the project's source files and targets
  +--Kconfig                      > Configure the Zephyr kernel and subsystems at build time to adapt them for specific application and platform needs.
  +--prj.config                   > This is a Kconfig fragment that specifies application-specific values for one or more Kconfig options.
  +--README.rst                   > Readme file of the project.
  +--sample.yaml                  > Sample definition and criteria.
```
If you want to develop your project, you should focus on some files that specify your projects, like the devicetree overlay file, CmakeLists.txt, Kconfig, and prj.config.

### Build the application ###

The `build` command helps you build Zephyr applications from the source. The easiest way is to go to your application’s root directory (i.e. the folder containing the application’s CMakeLists.txt file) and then run the following command:

`west build -b <BOARD_ID>`

In case, you don't know the exact board's ID, you can get the supported board list using the `west boards` command.

To set the application source directory explicitly, give its path as a positional argument:

`west build -b <BOARD_ID> <path/to/the/source/directory>`


For further information related to building the application, see [this section](https://docs.zephyrproject.org/latest/develop/west/build-flash-debug.html#building-west-build) for more details.


### Flash the application ###

From a Zephyr build directory, re-build the binary and flash it to your board:

`west flash`

To specify the build directory, you have to use `--build-dir` (or `-d`):

`west flash --build-dir path/to/build/directory`

If you don’t specify the build directory, `west flash` searches for one in the `build` directory in your current working directory.

**Note:**

- To flash the binary to the board, we advise installing and using the **SEGGER RTT J-Link** driver. You can download it [here](https://www.segger.com/downloads/jlink/).

### Logging data ##

You can launch Console, which is integrated into Simplicity Studio or use a third-party terminal tool such as Putty, TeraTerm or similar tools.

## References ##

Getting started with the [Developing with Zephyr](https://docs.zephyrproject.org/latest/develop/index.html) section on Zephyr's homepage.

For more information, visit the [Developer documentation](https://docs.silabs.com/application-examples/latest/) portal of Silicon Laboratories.

## Reporting Bugs/Issues and Posting Questions and Comments ##

To report bugs in the Application Examples projects, please create a new "Issue" in the "Issues" section of this repo. Please reference the board, project, and source files associated with the bug, and reference line numbers. If you are proposing a fix, also include information on the proposed fix. Since these examples are provided as-is, there is no guarantee that these examples will be updated to fix these issues.

Questions and comments related to these examples should be made by creating a new "Issue" in the "Issues" section of this repo.
