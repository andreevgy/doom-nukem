/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:07:00 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/12 11:55:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
**	rotate_left
**	rotate_right
**	Functions for rotating camera
*/

void	rotate_left(t_doom **w)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = (*w)->dir.x;
	old_plane_x = (*w)->plane.x;
	(*w)->dir.x = (*w)->dir.x * cos(RS) - (*w)->dir.y * sin(RS);
	(*w)->dir.y = old_dir_x * sin(RS) + (*w)->dir.y * cos(RS);
	(*w)->plane.x = (*w)->plane.x * cos(RS) - (*w)->plane.y * sin(RS);
	(*w)->plane.y = old_plane_x * sin(RS) + (*w)->plane.y * cos(RS);
}

void	rotate_right(t_doom **w)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = (*w)->dir.x;
	old_plane_x = (*w)->plane.x;
	(*w)->dir.x = (*w)->dir.x * cos(-RS) - (*w)->dir.y * sin(-RS);
	(*w)->dir.y = old_dir_x * sin(-RS) + (*w)->dir.y * cos(-RS);
	(*w)->plane.x = (*w)->plane.x * cos(-RS) - (*w)->plane.y * sin(-RS);
	(*w)->plane.y = old_plane_x * sin(-RS) + (*w)->plane.y * cos(-RS);
}
