/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:06:35 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/27 16:35:53 by marvin           ###   ########.fr       */
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
