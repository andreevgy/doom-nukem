/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:43:19 by marvin            #+#    #+#             */
/*   Updated: 2019/03/28 20:18:08 by marvin           ###   ########.fr       */
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
