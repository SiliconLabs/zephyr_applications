# Zephyr - Si7210 Hall Effect Magnetic Sensor #

## Summary ##

The example demonstrates how the Zephyr OS is supported by the development kits of Silicon Labs. In this example, you can see the utilization of the built-in Si7210 Hall Effect Magnetic sensor and an onboard LED with Zephyr OS.

The application makes the detection of magnetic objects possible, and it interacts with the onboard LED, which turns on to indicate a nearby magnetic object.

## Hardware Required ##

 - [EFR32BG22 Thunderboard Kit - BRD4184A](https://www.silabs.com/development-tools/thunderboard/thunderboard-bg22-kit?tab=overview)

**NOTE:**
Tested boards for working with this example:

| Board ID | Description  |
| ---------------------- | ------ |
| BRD4184A | [EFR32BG22 Thunderboard Kit - BRD4184A](https://www.silabs.com/development-tools/thunderboard/thunderboard-bg22-kit?tab=overview)    |
| BRD2601B | [EFR32xG24 Dev Kit - BRD2601B](https://www.silabs.com/development-tools/wireless/efr32xg24-dev-kit?tab=overview)    |

## Connections Required ##

You need a USB cable, which connects the board to your computer. The following picture shows the system view.

![hardware_connection](image/hardware_connection.png)

## Setup ##

To run the example, you should follow the below steps:

1. Copy this example directory to the `zephyrproject/zephyr/samples` directory or anywhere under the **zephyrproject** root directory.

2. Run **Command Prompt** as administrator and change the current working directory to this project directory using `cd` command.

3. Build this project by the following commands with a kind of tested board.

   - EFR32BG22 Thunderboard - BRD4184A: **`west build -p -b efr32bg22_brd4184a`**
   - EFR32xG24 Dev Kit - BRD2601B: **`west build -p -b efr32xg24_dk2601b`**

4. Flash the project to the board using **`west flash`** command.

**Note:**

- Make sure that the Zephyr OS environment is already installed. For installing the Zephyr OS environment, you can refer to [this guide](../README.md#setting-up-environment).

- You need to install the SEGGER RTT J-Link driver to flash this project to the board. For further information, please refer to [this section](../README.md#flash-the-application).

## How It Works ##

The example demonstrates the capability of magnetic object detection. The built-in Si7210 Hall Effect Magnetic sensor gets the magnetic induction value every second. If this value is greater than the configuration value, the onboard LED will turn on.

You can launch Console that is integrated into Simplicity Studio or use a third-party terminal tool like Putty or Tera Term to receive the data from the USB. You can see the threshold of magnetic induction and its value is logged out to your screen. Moreover, the LED status also displays on the screen. A screenshot of the console output is shown in the figure below.

![console_log](image/console_log.png)

You can configure the magnetic configuration value by running `west build -t menuconfig` or `west build -t guiconfig` command on this example working directory, which has the **Kconfig** file. Then, the project configuration window will appear as below.

| ![menu_config](image/menu_config.png) | ![guiconfig](image/guiconfig.png)|
| - | - |

After finishing the configuration, you have to re-build this example before flashing it to the board.
