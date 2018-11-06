#include "mbed.h"

#if !defined(MBED_SYS_STATS_ENABLED)
#error [NOT_SUPPORTED] test not supported
#endif

int main()
{
    mbed_stats_sys_t stats;
    mbed_stats_sys_get(&stats);

    printf("Mbed OS Version: %ld \n", stats.os_version);

    /* CPUID Register information
    [31:24]Implementer      0x41 = ARM
    [23:20]Variant          Major revision 0x0  =  Revision 0
    [19:16]Architecture     0xC  = Baseline Architecture
                            0xF  = Constant (Mainline Architecture?)
    [15:4]PartNO            0xC20 =  Cortex-M0
                            0xC60 = Cortex-M0+
                            0xC23 = Cortex-M3
                            0xC24 = Cortex-M4
                            0xC27 = Cortex-M7
                            0xD20 = Cortex-M23
                            0xD21 = Cortex-M33
    [3:0]Revision           Minor revision: 0x1 = Patch 1.
    */
    printf("CPU ID: 0x%x \n", stats.cpu_id);

    printf("Compiler ID: %d \n", stats.compiler_id);

    /* Compiler versions:
       ARM: PVVbbbb (P = Major; VV = Minor; bbbb = build number)
       GCC: VVRRPP  (VV = Version; RR = Revision; PP = Patch)
       IAR: VRRRPPP (V = Version; RRR = Revision; PPP = Patch)
    */
    printf("Compiler Version: %d \n", stats.compiler_version);

    /* RAM / ROM memory start and size information */
    for (int i = 0; i < MBED_MAX_MEM_REGIONS; i++) {
        if (stats.ram_size[i] != 0) {
            printf("RAM%d: Start 0x%x Size: 0x%x \n",i , stats.ram_start[i], stats.ram_size[i]);
        }
    }
    for (int i = 0; i < MBED_MAX_MEM_REGIONS; i++) {
        if (stats.rom_size[i] != 0) {
            printf("ROM%d: Start 0x%x Size: 0x%x \n",i, stats.rom_start[i], stats.rom_size[i]);
        }
    }
    return 0;
}
