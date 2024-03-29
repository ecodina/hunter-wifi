# Welcome to Hunter-WiFi's documentation

During 2020's summer I decided it would be interesting to have my Hunter Pro-C watering system connected to the Internet. After some research I found [Scott Shumate 2015's product](https://www.hackster.io/sshumate/hunter-sprinkler-wifi-remote-control-4ea918), but it is no longer on sale. Luckily, [Sebastien](https://github.com/seb821/OpenSprinkler-Firmware-Hunter) published the necessary Arduino code. I have adapted his code to make it easier to control the sprinkler system.

It can control up to 48 zones and 4 programs.

## In this documentation

You can find:

* The HTTP API reference
* The MQTT API reference
* How to connect the device to the SmartPort
* How to build the project

## Compatible devices

I have only tried it on a Hunter Pro-C, but it should work with any Hunter product that is SmartPort (Roam) compatible. Basically, it needs a REM pin.
More information on [Hunter's webpage](https://www.hunterindustries.com/en-metric/irrigation-product/remotes/roam).

## Bill of materials

This project has been built for a [WeMos D1 Mini Pro](https://docs.wemos.cc/en/latest/d1/d1_mini_pro.html), but should be easily adaptable to any ESP8266 board.
You will also need a floating power source (e.g. mobile phone charger).
In total, you will spend ~10€ to give WiFi capabilities to your old Hunter.

## Try it yourself
Download this project and [upload it to your board](/hunter-wifi/#!pages/buildupload.md). Afterwards, connect the microcontroller to the SmartPort (see how in the [docs](/hunter-wifi/#!pages/hunterconnection.md) folder).

The first time you power it, a "*WateringSystemAP*" open WiFi access point will be created. Connect to it and your phone will ask to "sign-in". Click on the notification and follow the steps to connect to your home WiFi. If nothing happens when you connect to the AP, navigate to 192.168.4.1.

When the board is connected to your home router, you will have an easy to use HTTP API (endpoints in the [docs](/hunter-wifi/#!pages/api.md) folder).

## Easy changes

You can change the AP's SSID and password-protect it by changing the values in `include/global_config.h`. You can also change the GPIO that connects to the REM pin of the Hunter system (by default, GPIO16 / D0).
