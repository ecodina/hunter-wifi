# Connection to the SmartPort

The Hunter SmartPort, which communicates with a proprietary protocol, consists of three pins:

 - AC#1 and AC#2: 24 VAC
 - REM: the data port, based on the 1-wire protocol.

The interesting part of this setup is that the REM port operates at 5 VDC with respect to the AC#2, which means that you need a floating power supply in order to align it to this pin.

My experience (and other people who also tried it), is that it will also work with the D1 Mini Pro's (or any Arduino) 3.3 VDC GPIO, so you won't need to buy a boost converter.

## 1. Using an external power supply

This is the set up I currently have. You can use any mobile phone charger to power the board, cutting the 5 VDC cable (normally red) and connect it to the AC#2.

You will also need to connect the GPIO16 / D0 (if using the default installation) to the REM port.

![Connection diagram](images/connection.png)


## 2. Using the 24 VAC from the SmartPort

This should be the best option, as you wouldn't need an external power source.

However, I bought a 24 VAC to 5 VDC converter but, after many tries, I couldn't work out the connections.