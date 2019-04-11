/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:13:06 by ghalvors          #+#    #+#             */
/*   Updated: 2019/04/11 15:56:24 by ghalvors         ###   ########.fr       */
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
	return (editor);
}

/* void		draw_editor(t_editor *editor)
{
	int x;
	ing y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			*(Uint32*)(editor-> + (y * W + x)
				* args->doom->surface->format->BytesPerPixel) = 0x1e6047;
		}
	}
} */

int			main(void)
{
	t_editor		*editor;

	editor = create_editor();
	while (editor->running)
		if (SDL_WaitEvent(&(editor->event)) >= 0)
		{
			SDL_UpdateWindowSurface(editor->window);
			if (key_press(editor->event, editor))
				SDL_UpdateWindowSurface(editor->window);
		}
	return (0);
}
