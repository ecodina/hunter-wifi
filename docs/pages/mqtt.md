# MQTT API Reference

Hint: work in progress

## Endpoint to check in

hunter/device_hostname/checkIn --> will publish online/rebooted/reconnected/Dead Somewhere

## Endpoint to check the result

hunter/device_hostname/result --> will publish the same result json as the [rest api](/hunter-wifi/pages/api.md)

## Endpoint to start and stop a zone

hunter/device_hostname/zone/XXX --> commands the zone with json payload to be published by the user ( {"action": "start","time": "1"} -- {"action": "stop"} )

## Endpoint to start a program

hunter/device_hostname/program/XXX --> commands the zone with json payload to be published by the user ( {"action": "start"} )
