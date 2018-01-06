#ifndef ADAU1761_INIT_H_
#define ADAU1761_INIT_H_


#define TABLE_END       		0xffff
#define ADAU1761_IIC_ADDRESS    0x38

//-----------------------------------------------------------------------------------------

// atomar register element
struct memory_cmd {
     unsigned short reg;
     unsigned char  val;
};

static struct memory_cmd adau1761_pll_stop[] = {
    { 0x4000 , 0x0e }, //*R0 Clock control          Disable
    {TABLE_END, 0x00}
};

static struct memory_cmd adau1761_pll_init[] = {
	{ 0x4002 , 0x00 }, // R1 PLL control
    { 0x4002 , 0x7D }, // R1 PLL control
    { 0x4002 , 0x00 }, // R1 PLL control
    { 0x4002 , 0x0C }, // R1 PLL control
    { 0x4002 , 0x23 }, // R1 PLL control
    { 0x4002 , 0x01 }, // R1 PLL control
	{TABLE_END, 0x00}
};

static struct memory_cmd adau1761_pll_start[] = {
    { 0x4000 , 0x0f }, //*R0 Clock control          Enable
    {TABLE_END, 0x00}
};

static struct memory_cmd adau1761_master[] = {
	{ 0x4015 , 0x01 }, // R15 Serial Port 0 - ; Become the I2S master.
	{ 0x400A , 0x01 }, // Reg[4] - Record mixer left control 0 - ; Setting all the input mixers
	{ 0x400B , 0x05 }, // Reg[5] - Record mixer left control 1 - MX1AUXG = 0db
	{ 0x400C , 0x01 }, // Reg[6] - Record mixer right control 0 - Just enable the mixer
	{ 0x400D , 0x05 }, // Reg[7] - Record mixer right control 1 - Record mixer right Control 1 - MX2AUXG = 0db
	{ 0x401C , 0x21 }, // Playback Mixer 3 left 0 - Setting all the output mixers
	{ 0x401E , 0x41 }, // Playback Mixer 4 right 0

	{ 0x4020 , 0x05}, // Mixer 5
	{ 0x4021 , 0x11}, // Mixer 6

	{ 0x4023 , 0xE7 }, // Playback Headphone volume left
	{ 0x4024 , 0xE7 }, // Playback Headphone volume right
    { 0x4025 , 0xFF }, // LOUTVOL Playback Line out volume left = 6 dB
    { 0x4026 , 0xFF }, // ROUTVOL Playback Line out volume right = 6 dB
	{ 0x4019 , 0x03 }, // ; Set up the ADC
	{ 0x4029 , 0x03 }, // ; Set up the DAC
	{ 0x402A , 0x03 }, // subaddress MSB
	{ 0x40F2 , 0x01 }, // R58 - Serial Input Route Control - ; Set up the signal routing
	{ 0x40F3 , 0x01 }, // R59 - Serial Output Route Control - ; Power up the various parts of the cores
	{ 0x40F9 , 0x7F }, // Reg[65] - Clock enable 0 - ; Power up the various parts of the cores
	{ 0x40FA , 0x03 }, // Reg[66] - Clock enable 1
    {TABLE_END, 0x00}
};

#endif
