#ifndef _INIT_DEVICES_H
#define _INIT_DEVICES_H

#include "lib.h"
#include "i8259.h"

/* PS/2 Controller Ports/ Commands*/
#define PS2_COMMAND_PORT    0x64 /* Command is sent */
#define PS2_DATA_PORT   0x60 /* Response byte is sent to this port, also inputs to the devices are sent to this port*/
#define READ_CTR_CONFIG 0x20
#define DISABLE_PS2_PORT1 0xAD
#define DISABLE_PS2_PORT2 0xA7
#define WRITE_PS2_DATA  0x60
#define TEST_PS2_CONTROLLER 0xAA
#define TEST_PS2_FIRST_PORT 0xAB
#define ENABLE_PS2_PORT1 0xAE
#define ENABLE_PS2_PORT2 0xA8

/* PS/2 Keyboard Commands */
#define RESET_DEVICE 0xFF

/* Mapping the IRQs to devices */
#define KEYBOARD_IRQ  1



#define READ_PS2_OUTPUT 0xD0

void init_ps2devices();

void keyboard_handler();

#endif
