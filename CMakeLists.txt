# use directory name for project id
get_filename_component(PROJECT ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT ${BOARD}-${PROJECT})

# TOP is absolute path to root directory of TinyUSB git repo
set(TOP "./tinyusb")
get_filename_component(TOP "${TOP}" REALPATH)

# Check for -DFAMILY=
if(FAMILY STREQUAL "rp2040")
  cmake_minimum_required(VERSION 3.12)
  set(PICO_SDK_PATH ${TOP}/hw/mcu/raspberrypi/pico-sdk)
  include(${PICO_SDK_PATH}/pico_sdk_init.cmake)
  project(${PROJECT})
  pico_sdk_init()
  add_executable(${PROJECT})

  include(${TOP}/hw/bsp/${FAMILY}/family.cmake)

  # Example source
  target_sources(${PROJECT} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/usb_descriptors.c
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Source/DAP.c
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Source/JTAG_DP.c
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Source/DAP_vendor.c
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Source/SWO.c
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Source/SW_DP.c
  )

 # Example include
  target_include_directories(${PROJECT} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/DAP/Firmware/Include/
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS_5/CMSIS/Core/Include/
    ${CMAKE_CURRENT_SOURCE_DIR}/bsp/${FAMILY}/
    ${CMAKE_CURRENT_SOURCE_DIR}/bsp/default/
  )

  # Example defines
  target_compile_definitions(${PROJECT} PUBLIC
  )

  target_link_libraries(${PROJECT} pico_stdlib)

  pico_add_extra_outputs(${PROJECT})

else()
  message(FATAL_ERROR "Invalid FAMILY specified")
endif()
