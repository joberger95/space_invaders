/*
 * alien.c
 *
 *  Created on: 27 janv. 2020
 *      Author: jordan
 */
#include "alien.h"
#include "serial.h"
#include "vt100.h"
#include "missile_move.h"

t_alien alien;
t_alien *ptr_alien = &alien;

void alien_init(void)
{
	for (int i = 0; i < NOMBREALIENX; i++)
	{
		for (int j = 0; j < NOMBREALIENY; j++)
		{
			ptr_alien->alien_army[1 + i][1 + j] = ALIENSKIN;
			vt100_move(i, j);
			serial_putchar(ptr_alien->alien_army[i][j]);
		}
	}
	ptr_alien->x = 0;
}

void alien_movement(void)
{
	int m = ptr_alien->x;
	if (m == 80 - NOMBREALIENX)
		ptr_alien->x = 0;
	while (m < (ptr_alien->x + NBCASES))
	{
		m++;
		for (int j = 0; j < NOMBREALIENY; j++)
		{
			vt100_move(m, j);
			serial_putchar(' ');
		}
	}
	ptr_alien->x = m;
	for (int numero_case = 0; numero_case < NBCASES; numero_case++)
	{
		for (int j = 0; j < NOMBREALIENY; j++)
		{
			vt100_move(numero_case + ptr_alien->x, j);
			serial_putchar(ptr_alien->alien_army[numero_case][j]);
		}
	}
}

