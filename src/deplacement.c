/*
 * deplacement.c
 *
 *  Created on: 22 janv. 2020
 *      Author: jordan
 */
#include "deplacement.h"
#include "serial.h"

#include "vt100.h"
#include "missile_move.h"

static char x = POSITION_X;
static char y = POSITION_Y;
static char carac_lu;

void deplacement(void)
{

	carac_lu = serial_get_last_char();


	if (carac_lu == DROITE) //Va a droite
	{
		vt100_move(x, y);
		serial_putchar(' ');
		x += 1;
		vt100_move(x, y);
		serial_putchar(SHIP);

	}
	if (carac_lu == GAUCHE) //Va a gauche
	{
		vt100_move(x, y);
		serial_putchar(' ');
		x -= 1;
		vt100_move(x, y);
		serial_putchar(SHIP);
	}
}
