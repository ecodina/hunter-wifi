# Build and upload

You can compile yourself the program and upload it to your board or use the precompiled binary under the releases section.

If using the WeMos D1 Mini, make sure to install the provided [Windows/Mac drivers](https://docs.wemos.cc/en/latest/ch340_driver.html).

## Precompiled binary

Use the *.bin* file under the releases section and `esptool.py` to upload the precompiled file to your board.

Usage:

    esptool.py --port <serial-port-of-ESP8266> write_flash -fm dio 0x00000 <precompiled-binary>.bin

You can find more documentation in the [*esptool.py* repository](https://github.com/espressif/esptool/).

## Build it yourself

If the above method didn't work or you want to make a few changes to the project before uploading to your board you can build the code yourself.

The `esp8266-hunter-sprinkler` folder is a PlatformIO project. Install Visual Studio Code (or any other IDE compatible with PlatformIO) and open the folder as a project.

After you make the changes, connect the board to your computer and upload it.

