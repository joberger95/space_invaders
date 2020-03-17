/*
 * alien.h
 *
 *  Created on: 27 janv. 2020
 *      Author: jordan
 */

#ifndef ALIEN_H_
#define ALIEN_H_

#define NBCASES (6)
#define NOMBREALIENX (7)
#define NOMBREALIENY (5)
#define ALIENSKIN ('O')

typedef struct
{
	unsigned char alien_army[NOMBREALIENX][NOMBREALIENY];
	unsigned char x;
	unsigned char y;
} t_alien;

extern t_alien *ptr_alien;

void alien_init(void);
void alien_movement(void);

#endif /* ALIEN_H_ */
