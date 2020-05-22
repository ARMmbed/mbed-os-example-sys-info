![](./resources/official_armmbed_example_badge.png)
# System information Mbed OS example

This example shows how to get system information onto an Mbed OS enabled platform.

You can build this project with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command-line interface tool [Arm Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

1. Install Mbed CLI.
1. From the command-line, import the example: `mbed import mbed-os-example-sys-info`
1. Change the current directory to where the project was imported.

## Application functionality

The `main()` function outputs on the serial interface information about the hardware (CPU, ROM and RAM), the firmware (version) and the compiler used to build the binary.

## Building and running

1. Connect a USB cable between the USB port on the target and the host computer.
1. Run the following command to build the example project and program the microcontroller flash memory:

   ```bash
   $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash --sterm
   ```
   
Note: You can use the Mbed CLI command-line option "--sterm" to open a serial terminal after flashing.

Your PC may take a few minutes to compile your code.

The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-sys-info.bin`.

Alternatively, you can manually copy the binary to the target, which gets mounted on the host computer through USB.

Depending on the target, you can build the example project with the `GCC_ARM`, `ARM` or `IAR` toolchain. After installing Arm Mbed CLI, run the command below to determine which toolchain supports your target:

```bash
$ mbed compile -S
```

## Expected output 

The serial terminal shows an output similar to: 

``` 
--- Terminal on /dev/ttyACM0 - 9600,8,N,1 ---
Mbed OS Version: 51500 
CPU ID: 0x410fc241 
Compiler ID: 1 
Compiler Version: 6130008 
RAM0: Start 0x20000000 Size: 0x30000 
RAM1: Start 0x1fff0000 Size: 0x10000 
ROM0: Start 0x0 Size: 0x100000 
``` 

You can use the CPU ID register, compiler ID and compiler version information below to interpret the above terminal logs.

CPU ID register information:

```
Bits [31:24] Implementer:  0x41 = ARM

Bits [23:20] Variant:      0x0 = Major revision

Bits [19:16] Architecture: 0xC  = Baseline Architecture,
                           0xF  = Constant (Mainline Architecture)

Bits [15:4] Part NO:       0xC20 =  Cortex-M0,
                           0xC60 = Cortex-M0+,
                           0xC23 = Cortex-M3,
                           0xC24 = Cortex-M4,
                           0xC27 = Cortex-M7,
                           0xD20 = Cortex-M23,
                           0xD21 = Cortex-M33

Bits [3:0] Revision:       Minor revision: 0x1 = Patch 1
```

Compiler IDs:

```
ARM = 1
GCC_ARM = 2
IAR = 3
```

Compiler versions:

```
ARM: PVVbbbb (P = Major; VV = Minor; bbbb = build number)
GCC: VVRRPP  (VV = Version; RR = Revision; PP = Patch)
IAR: VRRRPPP (V = Version; RRR = Revision; PPP = Patch)
```

## Configuring the application

You can enable the system statistics feature by setting `platform.sys-stats-enabled` to true in the application configuration file:

```
{
    "target_overrides": {
        "*": {            
            "platform.sys-stats-enabled": true            
        }
    }
}
```

## Troubleshooting 

If you have problems, you can review the [documentation](https://os.mbed.com/docs/latest/tutorials/debugging.html) for suggestions on what could be wrong and how to fix it. 

## Related links 

* [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html). 
* [Mbed OS configuration](https://os.mbed.com/docs/latest/reference/configuration.html). 
* [Mbed OS serial communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html). 
* [Mbed boards](https://os.mbed.com/platforms/).

### License and contributions

The software is provided under the Apache-2.0 license. Contributions to this project are accepted under the same license. Please see contributing.md for more information.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.
