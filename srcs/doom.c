/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:24:40 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/23 16:07:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	create_sprites(t_doom **doom)
{
	(*doom)->sprites[0] = (t_sprite){10, 10, 6, 0.0, {0, 0, 0}, {0, 0, 0}};
	(*doom)->sprites[1] = (t_sprite){10, 11, 8, 0.0, {0, 0, 0}, {0, 0, 0}};
	(*doom)->sprites[2] = (t_sprite){11.5, 12, 6, 0.0, {0, 0, 0}, {0, 0, 0}};
	(*doom)->sprites[3] = (t_sprite){12, 12, 7, 0.0, {0, 0, 0}, {0, 0, 0}};
}

t_doom	*create_doom(char *name)
{
	t_doom		*doom;

	SDL_Init(SDL_INIT_EVERYTHING);
	doom = (t_doom *)ft_memalloc(sizeof(t_doom));
	doom->running = 1;
	doom->pos.x = 0.0;
	doom->pos.y = 0.0;
	doom->dir.x = -1.0;
	doom->dir.y = 0.0;
	doom->plane.x = 0;
	doom->plane.y = 0.66;
	doom->vertical = 0;
	if (!read_map(&doom, name))
		return (NULL);
	if (!read_textures(&doom))
		return (NULL);
	if (!read_music(&doom))
		return (NULL);
	create_sprites(&doom);
	Mix_PlayMusic(doom->music, -1);
	doom->window = SDL_CreateWindow("doom3d", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_ALLOW_HIGHDPI);
	doom->surface = SDL_GetWindowSurface(doom->window);
	return (doom);
}
