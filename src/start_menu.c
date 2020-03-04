/*
 * start_menu.c
 *
 *  Created on: 22 janv. 2020
 *      Author: jordan
 */
#include "start_menu.h"
#include "serial.h"
#include "vt100.h"
static char start_game;

void start_menu(void)
{
	vt100_clear_screen();
	/*screen design loop*/
	for (int i = 0; i < SCREEN_WIDTH; i++)
	{
		vt100_move(i, 0);
		serial_putchar('#');
		vt100_move(i, 24);
		serial_putchar('#');
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		vt100_move(0, i);
		serial_putchar('#');
		vt100_move(80, i);
		serial_putchar('#');
	}
	/*Waiting for start begin*/
	while (start_game != START)
	{
		start_game = serial_get_last_char();
		vt100_move(34, 2);
		serial_puts("SPACE INVADERS");

		vt100_move(37, 3);
		serial_puts("by Jordan");

		vt100_move(29, 22);
		serial_puts("Press SPACE to begin");

		if (start_game == START)
		{
			vt100_clear_screen();
		}
	}
}

