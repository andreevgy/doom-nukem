/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:47:42 by marvin            #+#    #+#             */
/*   Updated: 2019/03/23 17:08:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_sprite(t_doom **doom, t_pixel pos, int tex_num)
{
	static int	i = 0;

	(*doom)->sprites[i].x = pos.x + 0.5;
	(*doom)->sprites[i].y = pos.y + 0.5;
	(*doom)->sprites[i].tn = abs(tex_num);
	i++;
}
