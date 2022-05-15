# Hunter Roam - WiFi

During 2020's summer I decided it would be interesting to have my Hunter Pro-C watering system connected to the Internet. After some research I found [Scott Shumate 2015's product](https://www.hackster.io/sshumate/hunter-sprinkler-wifi-remote-control-4ea918), but it is no longer on sale. Luckily, [Sebastien](https://github.com/seb821/OpenSprinkler-Firmware-Hunter) published the necessary Arduino code. I have adapted his code to make it easier to control the sprinkler system.

It can control up to 48 zones and 4 programs.

A quite extensive documentation is available on [this webpage](https://ecodina.github.io/hunter-wifi).

## Compatible devices

I have only tried it on a Hunter Pro-C, but it should work with any Hunter product that is SmartPort (Roam) compatible. Basically, it needs a REM pin.
More information on [Hunter's webpage](https://www.hunterindustries.com/en-metric/irrigation-product/remotes/roam).

## Bill of materials

This project has been built for a [WeMos D1 Mini Pro](https://docs.wemos.cc/en/latest/d1/d1_mini_pro.html), but should be easily adaptable to any ESP8266 board.
You will also need a floating power source (e.g. mobile phone charger).
In total, you will spend ~10€ to give WiFi capabilities to your old Hunter.

## Try it yourself
Download this project and [upload it to your board](docs/1%20Build%20and%20upload.md). Afterwards, connect the microcontroller to the SmartPort (see how in the [docs](docs/2%20Connection%20to%20the%20SmartPort.md) folder).

The first time you power it, a "*WateringSystemAP*" open WiFi access point will be created. Connect to it and your phone will ask to "sign-in". Click on the notification and follow the steps to connect to your home WiFi. If nothing happens when you connect to the AP, navigate to 192.168.4.1.

When the board is connected to your home router, you will have an easy to use HTTP API (endpoints in the [docs](docs/3%20API%20reference.md) folder).

## Easy changes

You can change the AP's SSID and password-protect it by changing the values in `include/global_config.h`. You can also change the GPIO that connects to the REM pin of the Hunter system (by default, GPIO16 / D0).

## What I'd like to see in the future

Feel free to fork this project and improve it. Some things that would be good to have are:

 - [x] Use of MQTT protocol.
 - [ ] API authentication.
 - [x] mDNS (easier to discover your device by using a `.local` domain).
 - [ ] Webpage (it only has an API).
 - [x] OTA support

## License

Given that [Sebastien](https://github.com/seb821/OpenSprinkler-Firmware-Hunter) published his code under the GNU GPL v3, this project follows the same license.

    Hunter Roam - WiFi
    Copyright (C) 2020-2022  Eloi Codina Torras
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
