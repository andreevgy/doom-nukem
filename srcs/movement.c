/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:06:35 by fmacgyve          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/03/28 20:25:52 by ghalvors         ###   ########.fr       */
=======
/*   Updated: 2019/03/28 16:41:45 by marvin           ###   ########.fr       */
>>>>>>> 8c6e4892ef04027acaa6e59f996db745a2f92050
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
**	move_forward
**	move_back
**	Functions for moving in maze
*/

void	move_forward(t_doom **doom)
{
	if ((*doom)->map[(int)(*doom)->pos.y]
		[(int)((*doom)->pos.x + (*doom)->dir.x * MOVE_SPEED)]->height != 1.0)
		(*doom)->pos.x += (*doom)->dir.x * MOVE_SPEED;
	if ((*doom)->map[(int)((*doom)->pos.y + (*doom)->dir.y * MOVE_SPEED)]
				[(int)((*doom)->pos.x)]->height != 1.0)
		(*doom)->pos.y += (*doom)->dir.y * MOVE_SPEED;
		printf("position: x %f\ty %f\n", (*doom)->pos.x, (*doom)->pos.y);
}

void	move_back(t_doom **doom)
{
	if ((*doom)->map[(int)(*doom)->pos.y]
		[(int)((*doom)->pos.x - (*doom)->dir.x * MOVE_SPEED)]->height != 1.0)
		(*doom)->pos.x -= (*doom)->dir.x * MOVE_SPEED;
	if ((*doom)->map[(int)((*doom)->pos.y - (*doom)->dir.y * MOVE_SPEED)]
				[(int)((*doom)->pos.x)]->height != 1.0)
		(*doom)->pos.y -= (*doom)->dir.y * MOVE_SPEED;
}
