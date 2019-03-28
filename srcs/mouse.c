/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:50:28 by ghalvors          #+#    #+#             */
/*   Updated: 2019/03/28 23:51:38 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
**	mouse_movement
**	controls mouse rotation
*/

int	mouse_movement(SDL_Event event, t_doom **doom)
{
	double	old_dir_x;
	double	old_plane_x;
	double	xrel;
	double	yrel;

	if (event.motion.type == SDL_MOUSEMOTION)
	{
		xrel = event.motion.xrel * -(*doom)->settings.x_mouse_speed;
		yrel = -event.motion.yrel * (*doom)->settings.y_mouse_speed;
		old_dir_x = (*doom)->dir.x;
		old_plane_x = (*doom)->plane.x;
		(*doom)->dir.x = (*doom)->dir.x * cos(xrel) - (*doom)->dir.y * sin(xrel);
		(*doom)->dir.y = old_dir_x * sin(xrel) + (*doom)->dir.y * cos(xrel);
		(*doom)->plane.x = (*doom)->plane.x * cos(xrel) - (*doom)->plane.y * sin(xrel);
		(*doom)->plane.y = old_plane_x * sin(xrel) + (*doom)->plane.y * cos(xrel);
		if (((*doom)->vertical >= -600 && yrel < 0) || ((*doom)->vertical <= 600 && yrel > 0))
				(*doom)->vertical += yrel;
		return (1);
	}
	return (0);
}

