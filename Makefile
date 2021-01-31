include ./tinyusb/tools/top.mk
include ./tinyusb/examples/make.mk

INC += \
	. \
	$(TOP)/lib/CMSIS_5/CMSIS/DAP/Firmware/Include \
	./bsp/$(BOARD) \
	./bsp/default \
	$(TOP)/hw

APP_SOURCE += $(wildcard ./*.c)

SRC_C += $(addprefix $(CURRENT_PATH)/, $(APP_SOURCE))

SRC_C += \
    ${TOP}/lib/CMSIS_5/CMSIS/DAP/Firmware/Source/DAP.c \
    ${TOP}/lib/CMSIS_5/CMSIS/DAP/Firmware/Source/JTAG_DP.c \
    ${TOP}/lib/CMSIS_5/CMSIS/DAP/Firmware/Source/DAP_vendor.c \
    ${TOP}/lib/CMSIS_5/CMSIS/DAP/Firmware/Source/SWO.c \
    ${TOP}/lib/CMSIS_5/CMSIS/DAP/Firmware/Source/SW_DP.c

include ./tinyusb/examples/rules.mk
