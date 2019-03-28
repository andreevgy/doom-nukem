/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:13:00 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/28 18:38:38 by marvin           ###   ########.fr       */
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
		if (doom->map[iter.y][iter.x]->height < 1.0)
			return (0);
		iter.x++;
	}
	iter.y = size->y - 1;
	iter.x = 0;
	while (iter.x < size->x)
	{
		if (doom->map[iter.y][iter.x]->height < 1.0)
			return (0);
		iter.x++;
	}
	return (1);
}

int			validate_map(t_doom *doom, t_pixel *size)
{
	t_pixel i;

	doom->sprites = ft_memalloc(sizeof(t_sprite) * doom->sprites_num);
	if (!check_horizontal_borders(doom, size))
		return (0);
	i.y = 0;
	while (++i.y < size->y - 1)
	{
		i.x = 0;
		if (doom->map[i.y][0]->height < 1.0 || doom->map[i.y][size->x - 1]->height < 1.0)
			return (0);
	}
	if (!doom->pos.x && !doom->pos.y)
		return (0);
	return (1);
}
