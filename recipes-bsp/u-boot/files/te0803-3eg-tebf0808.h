/*
 *
 * Configuration for te0803-3eg-tebf0808
 *
 */

#ifndef __TE0803_3EG_TEBF0808_H
#define __TE0803_3EG_TEBF0808_H

#define CONFIG_ZYNQ_I2C0
#define CONFIG_ZYNQ_I2C1
#define CONFIG_SYS_I2C_ZYNQ

#define CONFIG_EXTRA_ENV_SETTINGS \
    "nc=setenv stdout nc;setenv stdin nc;\0" \
    "ethaddr=00:0a:35:00:22:01\0" \
    "sdboot=echo boot Petalinux; run uenvboot ; mmcinfo && fatload mmc 1 ${netstart} ${kernel_img} && bootm \0" \
    "autoload=no\0" \
    "clobstart=0x10000000\0" \
    "netstart=0x10000000\0" \
    "dtbnetstart=0x11800000\0" \
    "loadaddr=0x10000000\0" \
    "bootenvsize=0x40000\0" \
        "bootenvstart=0x100000\0" \
        "boot_img=BOOT.BIN\0" \
    "kernel_img=image.ub\0" \
        "load_boot=tftpboot ${clobstart} ${boot_img}\0" \
    "install_boot=mmcinfo && fatwrite mmc 1 ${clobstart} ${boot_img} ${filesize}\0" \
    "eraseenv=sf probe 0 && sf erase ${bootenvstart} ${bootenvsize}\0" \
    "load_kernel=tftpboot ${clobstart} ${kernel_img}\0" \
    "update_kernel=setenv img kernel; setenv psize ${kernelsize}; setenv installcmd \"install_kernel\"; run load_kernel ${installcmd}; setenv img; setenv psize; setenv installcmd\0" \
    "install_kernel=mmcinfo && fatwrite mmc 1 ${clobstart} ${kernel_img} ${filesize}\0" \
    "cp_kernel2ram=mmcinfo && fatload mmc 1 ${netstart} ${kernel_img}\0" \
    "fault=echo ${img} image size is greater than allocated place - partition ${img} is NOT UPDATED\0" \
    "test_crc=if imi ${clobstart}; then run test_img; else echo ${img} Bad CRC - ${img} is NOT UPDATED; fi\0" \
    "test_img=setenv var \"if test ${filesize} -gt ${psize}\\; then run fault\\; else run ${installcmd}\\; fi\"; run var; setenv var\0" \
    "netboot=tftpboot ${netstart} ${kernel_img} && bootm\0" \
    "default_bootcmd=run cp_kernel2ram && bootm ${netstart}\0" \
""


/* BOOTCOMMAND */
/*#define CONFIG_BOOTCOMMAND	"run default_bootcmd"*/

#include <configs/xilinx_zynqmp.h>


#endif /* __TE0803_3EG_TEBF0808_H */
