/*
 * missile_move.c
 *
 *  Created on: 22 janv. 2020
 *      Author: jordan
 */
#include "missile_move.h"
#include "vt100.h"
#include "serial.h"
#include "alien.h"
#include "deplacement.h"

void missile_shoot(unsigned char x, unsigned char y)
{
	if (y > 0)
	{
		vt100_move(x, y);
		serial_putchar(' ');
		vt100_move(x, y - 1);
		serial_putchar('|');
	}
	if (y == 0)
	{
		answer_shoot = 0;
		vt100_move(x, y);
		serial_putchar(' ');
	}
	if (y == ptr_alien->y)
		ptr_alien->alien_army[x][y] = 'v';

}
