/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:43:19 by marvin            #+#    #+#             */
/*   Updated: 2019/03/27 17:55:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"


t_block		*create_block(double height, int texture)
{
	t_block *block;

	block = ft_memalloc(sizeof(t_block));
	block->height = height;
	block->texture = texture;
	return (block);
}

t_smallwall	*create_small_wall(t_pixel pos, double height, double dist, int side)
{
	t_smallwall *wall;

	wall = ft_memalloc(sizeof(t_smallwall));
	wall->pos = pos;
	wall->height = height;
	wall->side = side;
	wall->next = NULL;
	wall->dist = dist;
	return (wall);
}

void add_wall(t_smallwall **wall, t_pixel pos, double height, double dist, int side)
{
	t_smallwall	*new;

	new = create_small_wall(pos, height, dist, side);
	new->next = *wall;
	*wall = &(*new);
}
