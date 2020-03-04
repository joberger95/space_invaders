/*
 * initialisation.c
 *
 *  Created on: 22 janv. 2020
 *      Author: jordan
 */

#include "serial.h"
#include "vt100.h"
#include "initialisation.h"

void init(void)
{
	serial_init(BAUDS);
	vt100_clear_screen();
}

