# Caprica Soil Hygrometer

This repository contains code to integrate an Arduino-based soil hygrometer into the Caprica home automation suite.

## Overview
This repository is used to set up a system with an Arduino-based hygrometer communicating back to the Caprica hub.

Basically I'm terrible at growing plants but I'm OK at electronics and writing code, so I figured I'd use the latter 
to do the former. A hygrometer measures soil moisture content, by measuring the resistance between two probes in the 
soil. More moist soil has higher conductivity/lower resistance, so as the soil dries out, you can watch the resistance
increase.

This system consists of two parts. An Arduino with a hygrometer and an RF transceiver sits at the planter box, and wirelessly
communicates to another transceiver connected to a Raspberry Pi's GPIO ports.

Progress on this has been stalled for a while, due to ruining my hygrometer -- I was taking measurements continuously, 
which I think was basically just electrolyzing the water in the soil. The contacts on the hygrometer got horribly
oxidized, and I haven't replaced it yet.

### Arduino
The Arduino (or similar compatible microcontroller) side consists of a simple sketch to read data from a YL-38 +  YL-69 hygrometer and controller combination.

This data is then broadcast via an nRF24L01+ transciever to the hub, where the data is processed and integrated into the Caprica webspage.

### Hub
The hub side of the code is designed for a Raspberry Pi with an nRF24L01+ transceiver operating in receive mode. It captures data broadcast from the Arduino peripheral.

A python wrapper exists, for eventual integration into the Django website.

## TODOs
- Rework the receiver code in python to avoid needing a wrapper for it.
- Find a way around needing to run receiver code as root. This may be a limitation of RPi GPIO for now...
