cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ATmega32_Project LANGUAGES C)

# Set the microcontroller and clock frequency
set(MCU atmega32)
set(F_CPU 8000000UL) # 8 MHz clock frequency

# Set the programmer and port (adjust based on your setup)
set(PROGRAMMER usbasp) # e.g., usbasp or arduino
set(PORT /dev/ttyUSB0) # Adjust for your system

# Set the compiler
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(AVR_OBJCOPY avr-objcopy)
set(AVR_SIZE avr-size)
set(AVRDUDE avrdude)

# Add standard compiler flags
set(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os -Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-Os")

# Source files (relative to the CMakeLists.txt file)
set(SRC_FILES
    main.c
    MCAL/DIO/DIO_program.c
)

# Include directories (add paths for headers here)
include_directories(
    common/stdlib
    MCAL/DIO
    HAL
)

# Add executable
add_executable(${PROJECT_NAME}.elf ${SRC_FILES})

# Add custom commands to generate HEX and upload to the microcontroller
add_custom_target(generate_hex ALL
    COMMAND ${AVR_OBJCOPY} -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    DEPENDS ${PROJECT_NAME}.elf
)

add_custom_target(upload ALL
    COMMAND ${AVRDUDE} -c ${PROGRAMMER} -p ${MCU} -P ${PORT} -U flash:w:${PROJECT_NAME}.hex
    DEPENDS generate_hex
)

# Print size of the compiled program
add_custom_command(TARGET generate_hex POST_BUILD
    COMMAND ${AVR_SIZE} --mcu=${MCU} -C ${PROJECT_NAME}.elf
)
