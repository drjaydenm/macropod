# macropod

A basic macro keyboard built from the ground up

## Setup

### Install the GNU Toolchain for ARM Embedded Processors

The toolchain is required to compile for the STM32 target platform

#### MacOS

``` {.bash}
brew tap osx-cross/arm

brew install arm-gcc-bin

brew install stlink
```

## Building

Run the build

``` {.bash}
make
```

Flash to device

``` {.bash}
make flash
```

Inspect memory layout of image

``` {.bash}
arm-none-eabi-nm main.elf
```

## Debugging with GDB

### ST-Link GDB Server

``` {.bash}
st-util
```

### J-Link GDB Server

``` {.bash}
JLinkGDBServer -if swd -device STM32F042K6 -port 4242
```

### GDB

``` {.bash}
cd ./code

arm-none-eabi-gdb main.elf

target extended-remote :4242

load

continue

Ctrl^C

info registers

stepi

info registers

quit
```
