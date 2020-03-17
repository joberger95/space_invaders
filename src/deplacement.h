/*
 * deplacement.h
 *
 *  Created on: 22 janv. 2020
 *      Author: jordan
 */

#ifndef DEPLACEMENT_H_
#define DEPLACEMENT_H_

#define LEFT ('q')
#define RIGHT ('d')
#define SPACE (' ')
#define POSITION_X (0)
#define POSITION_Y (23)
#define SHIP ('V')


typedef struct
{
	char shoot_status;
	char position_x;
	char position_y;
} t_status;

extern t_status *ptr_status;
extern unsigned char answer_shoot;

char deplacement();

#endif /* DEPLACEMENT_H_ */
