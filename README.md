## Dapper Mime

This unearths the name of a weekend project that I did in 2014.  Both then and now, this is a port of [ARM's CMSIS-DAP code](https://github.com/arm-software/CMSIS_5) to a platform without the need for an expensive proprietary compiler and USB drivers.

Whereas the original code used ST's STM32 USB drivers, this new iteration uses [TinyUSB](https://github.com/hathach/tinyusb), an open source cross-platform USB stack for embedded systems.

## Variants

Most [TinyUSB supported MCUs](https://github.com/hathach/tinyusb/blob/master/docs/boards.md) can run this code; a subdirectory under bsp needs to be added for the "BOARD" name with a DAP_config.h to control the SWD/JTAG GPIOs and a unique.h to provide unique serial number (if any) and prefix to the USB product name.

Already added BOARD variants include:

For BOARD=raspberry_pi_pico, this project results in a standards-based CMSIS-DAP alternative to the approaches suggested in Chapter 5 and Appendix A of [Getting Started with Raspberry Pi Pico](https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf).  This uses two RP2040 boards (see [wiring loom shown in Figure 34](https://user-images.githubusercontent.com/12226419/134785445-5f651d5a-eda9-4e94-8860-d2ef619dc27a.png) of Appendix A) where one RP2040 is the debugger and the other RP2040 is being debugged.  The instructions in Chapter 5 apply, except no Raspberry Pi is needed.

Alternatively, a special one RP2040 “Raspberry Pi Pico” variant is [available here](https://github.com/majbthrd/pico-debug).

For BOARD=stm32f072disco, the inexpensive [32F072BDISCOVERY evaluation board](https://www.st.com/en/evaluation-tools/32f072bdiscovery.html) can be used as a CMSIS-DAP SWD debugger.

## Building

Unless you have a burning desire to build this from scratch, consider just downloading pre-build images [from the selection here](https://github.com/majbthrd/DapperMime/releases).

If, however, you are determined to build from scratch (for example, if you are planning to port Dapper Mime to an additional MCU), after initially downloading this project's code, issue the following command to download TinyUSB and CMSIS_5 code (as well as all submodules):

```
git submodule update --init --recursive
```

Follow the TinyUSB build instructions [available here](https://github.com/hathach/tinyusb/blob/master/docs/reference/getting_started.rst), but issue the make command in the base directory of Dapper Mime.

Note that each TinyUSB board name being targeted needs a corresponding subdirectory under the Dapper Mime ./bsp/ subdirectory and a customized version of DAP_config.h for the target.

## License

TinyUSB is licensed under the [MIT license](https://opensource.org/licenses/MIT).

ARM's CMSIS_5 code is licensed under the [Apache 2.0 license](https://opensource.org/licenses/Apache-2.0).

Source code files within this project are licensed under the [MIT license](https://opensource.org/licenses/MIT) unless otherwise stated.

