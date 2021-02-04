## Dapper Mime

This unearths the name of a weekend project that I did in 2014.  Both then and now, this is a port of [ARM's CMSIS-DAP code](https://github.com/arm-software/CMSIS_5) to a platform without the need for an expensive proprietary compiler and USB drivers.

Whereas the original code used ST's STM32 USB drivers, this new iteration uses [TinyUSB](https://github.com/hathach/tinyusb), an open source cross-platform USB stack for embedded systems.

## Special Variants

A variant tailored especially for the RP2040 “Raspberry Pi Pico” is [available here](https://github.com/majbthrd/pico-debug).

## Building

After initially downloading this project's code, issue the following command to download TinyUSB and CMSIS_5 code (as well as all submodules):

```
git submodule update --init --recursive
```

Follow the TinyUSB build instructions [available here](https://github.com/hathach/tinyusb/tree/master/docs), but issue the make command in the base directory of Dapper Mime.

Note that each TinyUSB board name being targeted needs a corresponding subdirectory under the Dapper Mime ./bsp/ subdirectory and a customized version of DAP_config.h for the target.

## License

TinyUSB is licensed under the [MIT license](https://opensource.org/licenses/MIT).

ARM's CMSIS_5 code is licensed under the [Apache 2.0 license](https://opensource.org/licenses/Apache-2.0).

