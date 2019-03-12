/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:24:40 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/12 16:39:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_doom	*create_doom(char *name)
{
	t_doom	*doom;

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
	Mix_PlayMusic(doom->music, -1);
	doom->window = SDL_CreateWindow("doom3d", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_ALLOW_HIGHDPI);
	doom->surface = SDL_GetWindowSurface(doom->window);
	return (doom);
}
