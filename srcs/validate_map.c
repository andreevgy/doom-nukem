/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:13:00 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/23 16:01:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int	check_horizontal_borders(t_doom *doom, t_pixel *size)
{
	t_pixel iter;

	iter.y = 0;
	iter.x = 0;
	while (iter.x < size->x)
	{
		if (doom->map[iter.y][iter.x] <= 0)
			return (0);
		iter.x++;
	}
	iter.y = size->y - 1;
	iter.x = 0;
	while (iter.x < size->x)
	{
		if (doom->map[iter.y][iter.x] <= 0)
			return (0);
		iter.x++;
	}
	return (1);
}

static void	set_initial_pos(t_doom *doom, t_pixel pos)
{
	if (!doom->pos.x && !doom->pos.y)
	{
		doom->pos.x = pos.x + 0.5;
		doom->pos.y = pos.y + 0.5;
	}
	doom->map[pos.y][pos.x] = 0;
}

int			validate_map(t_doom *doom, t_pixel *size)
{
	t_pixel i;

	if (!check_horizontal_borders(doom, size))
		return (0);
	i.y = 0;
	while (++i.y < size->y - 1)
	{
		i.x = 0;
		if (doom->map[i.y][0] <= 0 || doom->map[i.y][size->x - 1] <= 0)
			return (0);
		while (++i.x <= size->x - 1)
		{
			if (doom->map[i.y][i.x] == -1 && !doom->pos.x && !doom->pos.y)
				set_initial_pos(doom, i);
			else if (doom->map[i.y][i.x] == -1 && doom->pos.x && doom->pos.y)
				return (0);
		}
	}
	if (!doom->pos.x && !doom->pos.y)
		return (0);
	return (1);
}
