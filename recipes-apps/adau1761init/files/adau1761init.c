/*
-- Company: Trenz Electronic GmbH
-- Engineer: Oleksandr Kiyenko
 */
#include <stdio.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "adau1761init.h"

unsigned char i2c_reg_read(int dev_file, unsigned char dev_addr, const unsigned short reg_addr){
    __u8 inbuf[2];
    __u8 outbuf[2];
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[2];

    /*
    * In order to read a register, we first do a "dummy write" by writing
    * 0 bytes to the register we want to read from.  This is similar to
    * the packet in set_i2c_register, except it's 1 byte rather than 2.
    */
    outbuf[0]           = reg_addr >> 8;
    outbuf[1]           = reg_addr & 0xFF;
    messages[0].addr    = dev_addr;
    messages[0].flags   = 0;
    messages[0].len     = 2,            //sizeof(outbuf);
    messages[0].buf     = &outbuf;
    /* The data will get returned in this structure */
    messages[1].addr    = dev_addr;
    messages[1].flags   = I2C_M_RD;     /* | I2C_M_NOSTART*/
    messages[1].len     = 1,            //sizeof(inbuf);
    messages[1].buf     = inbuf;

    /* Send the request to the kernel and get the result back */
    packets.msgs        = messages;
    packets.nmsgs       = 2;
    if(ioctl(dev_file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return 1;
    }

    return inbuf[0];
}

int i2c_block_read(int dev_file, unsigned char dev_addr, const unsigned short reg_addr, unsigned char* buf){
    __u8 outbuf[2];
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[2];

    outbuf[0]           = reg_addr >> 8;
    outbuf[1]           = reg_addr & 0xFF;
    messages[0].addr    = dev_addr;
    messages[0].flags   = 0;
    messages[0].len     = 2;            //sizeof(outbuf);
    messages[0].buf     = &outbuf;
    messages[1].addr    = dev_addr;
    messages[1].flags   = I2C_M_RD;
    messages[1].len     = 6;       
    messages[1].buf     = buf;

    packets.msgs        = messages;
    packets.nmsgs       = 2;
    if(ioctl(dev_file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return 1;
    }

	return 0;
}

int i2c_reg_write(int dev_file, unsigned char dev_addr, unsigned short reg_addr, unsigned char reg_data)
{
    unsigned char outbuf[3];
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[1];

    messages[0].addr    = dev_addr;
    messages[0].flags   = 0;
    messages[0].len     = sizeof(outbuf);
    messages[0].buf     = &outbuf;
    /* The first byte indicates which register we'll write */
    outbuf[0]           = reg_addr >> 8;
    outbuf[1]           = reg_addr & 0xFF;
    outbuf[2]           = reg_data;
    /* Transfer the i2c packets to the kernel and verify it worked */
    packets.msgs        = messages;
    packets.nmsgs       = 1;
    if(ioctl(dev_file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return 1;
    }

    return 0;
}

static void i2c_set_write(int dev_file, unsigned char dev_addr, struct memory_cmd *set){
    int i;
    for(i=0; set[i].reg != TABLE_END; i++){
        i2c_reg_write(dev_file, dev_addr, set[i].reg, set[i].val);
    }
}

int i2c_set_burst(int dev_file, unsigned char dev_addr, struct memory_cmd *set){
    unsigned char outbuf[256];
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[256];
	int i;

    messages[0].addr    = dev_addr;
    messages[0].flags   = 0;
    messages[0].buf     = &outbuf;
    /* The first byte indicates which register we'll write */
    outbuf[0]           = set[0].reg >> 8;
    outbuf[1]           = set[0].reg & 0xFF;
	for(i = 0; set[i].reg != TABLE_END; i++){
		outbuf[i+2]		= set[i].val;
	}
	messages[0].len     = 2 + i;
    /* Transfer the i2c packets to the kernel and verify it worked */
    packets.msgs        = messages;
    packets.nmsgs       = 1;
    if(ioctl(dev_file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return 1;
    }

    return 0;
}


int main(int argc, char *argv[])
{
    int i2c_file, i, j;
    unsigned short model_id;
    unsigned int lot_id;
    unsigned short chip_id;
    unsigned char ret;
	unsigned char read_buf[6];

    printf("ADAU1761 Init v1.0\n");
    if(argc < 2){
        printf("%s /dev/i2c-X\n",argv[0]);
        return 1;
    }

    if ((i2c_file = open(argv[1], O_RDWR)) < 0) {
        perror("Unable to open i2c control file");
        return 1;
    }

	i2c_set_write(i2c_file, ADAU1761_IIC_ADDRESS, adau1761_pll_stop);   // Stop PLL before configuration
	i2c_set_burst(i2c_file, ADAU1761_IIC_ADDRESS, adau1761_pll_init);   // Write PLL configuration

	for(i = 0; i < 200; i++){
		i2c_block_read(i2c_file, ADAU1761_IIC_ADDRESS, 0x4002, read_buf);
		if((read_buf[5] & 0x02) == 0x02){	// Pll Lock Bit
			break;
		}
		usleep(1);
	}
	if((read_buf[5] & 0x02) == 0x00){   // Pll Lock Bit from last read
		perror("PLL Lock failed");
		close(i2c_file);
		return 1;
	}

    i2c_set_write(i2c_file, ADAU1761_IIC_ADDRESS, adau1761_pll_start);  // Start PLL
    usleep(64);                                                         // Wait
	i2c_set_write(i2c_file, ADAU1761_IIC_ADDRESS, adau1761_master);		// Load common configuration

    close(i2c_file);
    return 0;
}

