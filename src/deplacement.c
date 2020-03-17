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

static unsigned char x = POSITION_X;
static unsigned char y = POSITION_Y;
static unsigned char carac_lu;
unsigned char answer_shoot;
t_status status;
t_status *ptr_status = &status;


char deplacement(void)
{

	carac_lu = serial_get_last_char();

	if (carac_lu == RIGHT) //Va a droite
	{
		vt100_move(x, y);
		serial_putchar(' ');
		x += 1;
		vt100_move(x, y);
		serial_putchar(SHIP);

	}
	if (carac_lu == LEFT) //Va a gauche
	{
		vt100_move(x, y);
		serial_putchar(' ');
		x -= 1;
		vt100_move(x, y);
		serial_putchar(SHIP);
	}
	if (carac_lu == SPACE)
	{
		ptr_status->shoot_status = 1;
		ptr_status->position_x = x;
		ptr_status->position_y = y;
		answer_shoot = 1;
	}
	return 0;
}
