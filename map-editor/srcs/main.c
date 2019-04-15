/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <hkuphal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:13:06 by ghalvors          #+#    #+#             */
/*   Updated: 2019/04/15 19:15:29 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_editor.h"
#include <stdlib.h>

t_editor	*create_editor()
{
	t_editor	*editor;

	SDL_Init(SDL_INIT_EVERYTHING);
	editor = (t_editor *)malloc(sizeof(t_editor));
	editor->window = SDL_CreateWindow("Map editor", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_ALLOW_HIGHDPI);
	editor->surface = SDL_GetWindowSurface(editor->window);
	editor->running = 1;
	editor->move_x = 0;
	editor->move_y = 0;
	ft_bzero(editor->map, sizeof(editor->map));
	editor->sectors = NULL;
	return (editor);
}

void		draw_editor(t_editor *editor)
{
	int x;
	int y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			*(Uint32*)(editor->surface->pixels + (y * W + x)
				* editor->surface->format->BytesPerPixel) = 0x1e6047;
			x += STEP;
		}
		y += STEP;
	}
}

int			main(void)
{
	t_editor		*editor;

	editor = create_editor();
	draw_editor(editor);
	while (editor->running)
		if (SDL_WaitEvent(&(editor->event)) >= 0)
		{
			SDL_UpdateWindowSurface(editor->window);
			if (key_press(editor->event, editor) || set_point(editor->event, editor))
				SDL_UpdateWindowSurface(editor->window);
		}
	return (0);
}
