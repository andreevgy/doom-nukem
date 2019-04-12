/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:24:58 by ghalvors          #+#    #+#             */
/*   Updated: 2019/04/12 14:46:02 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_editor.h"

int	key_press(SDL_Event event, t_editor *editor)
{
	(void)event;
	if ((SDL_QUIT == editor->event.type) || (SDL_KEYDOWN == editor->event.type
			&& SDL_SCANCODE_ESCAPE == editor->event.key.keysym.scancode))
		editor->running = 0;
		if (event.key.keysym.scancode == SDL_SCANCODE_UP)
			editor->move_x += 100;
		if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
			editor->move_x -= 100;
		if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
			editor->move_y += 100;
		if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			editor->move_y -= 100;
	return (0);
}

void	to_nearest_point(int *x, int *y)
{
	if (*x % STEP >= STEP / 2)
		*x += (STEP - (*x % STEP));
	else
		*x -= *x % STEP;
	if (*y % STEP >= STEP / 2)
		*y += (STEP - (*y % STEP));
	else
		*y -= *y % STEP;
}

void	put_point(t_editor *editor, t_point *point)
{
	int i;
	int j;

	i = point->y - 4;
	while (++i < point->y + 3)
	{
		j = point->x - 4;
		while (++j < point->x + 3)
		{
			if ((j >= 0 && j < W) && (i >= 0 && i < H))
			*(Uint32*)(editor->surface->pixels + (i * W + j)
			* editor->surface->format->BytesPerPixel) = 0xff0000;
		}
	}
}

void	init_sector(t_editor *editor)
{
	if (!(editor->sectors = malloc(sizeof(t_sector))))
		exit(EXIT_FAILURE);
	
}

void	perform_sector(t_editor *editor, t_point *point)
{
	if (!(editor->sectors))
		init_sector(editor);
}

int	set_point(SDL_Event event, t_editor *editor)
{
	t_point	*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		exit(EXIT_FAILURE);	
	if (event.motion.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&point->x, &point->y);
			to_nearest_point(&point->x, &point->y);
			perform_sector(editor, point);
			if (editor->map[point->x / STEP][point->y / STEP] == 0)
			{
				editor->map[point->x / STEP][point->y / STEP] = 1;
				put_point(editor, &point);
			}
		}
	}
	return (0);
}