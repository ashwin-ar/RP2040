cmake_minimum_required(VERSION 3.12)


include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(pico-projects C CXX ASM)

pico_sdk_init()
if (TARGET tinyusb_device)
add_executable(blink_Test blink_Test.c)

target_link_libraries(blink_Test pico_stdlib hardware_gpio hardware_timer)
pico_enable_stdio_usb(blink_Test 1)
pico_enable_stdio_uart(blink_Test 0)
pico_add_extra_outputs(blink_Test)

pico_add_extra_outputs(blink_Test)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()