# Caprica Soil Hygrometer

This repository contains code to integrate an Arduino-based soil hygrometer into the Caprica home automation suite.

## Overview
This repository is used to set up a system with an Arduino-based hygrometer communicating back to the Caprica hub.

### Arduino
The Arduino (or similar compatible microcontroller) side consists of a simple sketch to read data from a YL-38 +  YL-69 hygrometer and controller combination.

This data is then broadcast via an nRF24L01+ transciever to the hub, where the data is processed and integrated into the Caprica webspage.

### Hub
The hub side of the code is designed for a Raspberry Pi with an nRF24L01+ transceiver operating in receive mode. It captures data broadcast from the Arduino peripheral.

A python wrapper exists, for eventual integration into the Django website.

## TODOs
- Rework the receiver code in python to avoid needing a wrapper for it.
- Find a way around needing to run receiver code as root. This may be a limitation of RPi GPIO for now...
