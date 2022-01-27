cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/tinyusb/hw/bsp/family_support.cmake)

# gets PROJECT name for the example (e.g. <BOARD>-<DIR_NAME>)
get_filename_component(PROJECT ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT ${BOARD}-${PROJECT})

project(${PROJECT})

# Checks this example is valid for the family and initializes the project
family_initialize_project(${PROJECT} ${CMAKE_CURRENT_LIST_DIR})

add_executable(${PROJECT})

# Example source
target_sources(${PROJECT} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/main.c
        ${CMAKE_CURRENT_SOURCE_DIR}/usb_descriptors.c
        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Source/DAP.c
        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Source/JTAG_DP.c
        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Source/DAP_vendor.c
        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Source/SWO.c
        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Source/SW_DP.c
        ${CMAKE_CURRENT_SOURCE_DIR}/bsp/${FAMILY}/cdc_uart.c
        )

# Example include
target_include_directories(${PROJECT} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Include/
        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/Core/Include/
        ${CMAKE_CURRENT_SOURCE_DIR}/bsp/${FAMILY}/
        ${CMAKE_CURRENT_SOURCE_DIR}/bsp/default/
        )

target_link_libraries(${PROJECT} PUBLIC pico_unique_id)

# Configure compilation flags and libraries for the example... see the corresponding function
# in hw/bsp/FAMILY/family.cmake for details.
family_configure_device_example(${PROJECT})
