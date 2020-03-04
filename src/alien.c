/*
 * alien.c
 *
 *  Created on: 27 janv. 2020
 *      Author: jordan
 */
#include "alien.h"
#include "serial.h"
#include "vt100.h"

typedef struct
{
	char alien_army[NOMBREALIENX][NOMBREALIENY];
	char x;
	char y;
} t_alien;

static t_alien alien;
static t_alien *ptr = &alien;

void alien_init(void)
{
	for (int i = 0; i < NOMBREALIENX; i++)
	{
		for (int j = 0; j < NOMBREALIENY; j++)
		{
			ptr->alien_army[1 + i][1 + j] = 'O';
			vt100_move(i, j);
			serial_putchar(ptr->alien_army[i][j]);
		}
	}
	ptr->x = 0;
}

void alien_movement(void)
{
	int m = ptr->x;
	while (m < (ptr->x + NBCASES))
	{
		m++;
		for (int j = 0; j < NOMBREALIENY; j++)
		{
			vt100_move(m, j);
			serial_putchar(' ');
		}
	}
	for (int numero_case = 0; numero_case < NBCASES; numero_case++)
	{
		for (int j = 0; j < NOMBREALIENY; j++)
		{
			vt100_move(numero_case + ptr->x, j);
			serial_putchar(ptr->alien_army[numero_case][j]);
		}
	}
}

