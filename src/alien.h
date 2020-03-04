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

typedef struct
{
	char alien_army[NOMBREALIENX][NOMBREALIENY];
	char x;
	char y;
} t_alien;

void alien_init(void);
void alien_movement(void);

#endif /* ALIEN_H_ */
