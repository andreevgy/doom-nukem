/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:24:58 by ghalvors          #+#    #+#             */
/*   Updated: 2019/04/20 14:33:22 by fmacgyve         ###   ########.fr       */
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

void	render_point(t_editor *editor, t_point *point)
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
	t_sector *head;
	t_sector *sec;

	if (!editor->sectors)
	{
		if (!(editor->sectors = (t_sector*)malloc(sizeof(t_sector))))
			exit(EXIT_FAILURE);
		editor->sectors->next = NULL;
	}
	else
	{
		head = editor->sectors;
		if (!(sec = (t_sector*)malloc(sizeof(t_sector))))
			exit(EXIT_FAILURE);
		sec->next = head;
		editor->sectors = sec;
	}
	editor->sectors->is_closed = 0;
	editor->sectors->point = NULL;
}

void	add_point(t_sector *sector, t_point *point)
{
	t_point *temp;

	if (!sector->point)
	{
		sector->point = point;
		printf("First point added\n");
		sector->last_point = sector->point;
		sector->vertices = 1;
	}
	else
	{
		temp = sector->point;
		while(temp->next)
		{
			if (point->x == temp->x ||
			point->y == temp->y)
				return ;
			temp = temp->next;
		}
		sector->last_point->next = point;
		sector->last_point = sector->last_point->next;
		printf("Point added\n");
		sector->vertices += 1;
	}
}

void	perform_sector(t_editor *editor, t_point *point)
{
	if (!(editor->sectors) || editor->sectors->is_closed == 1)
		init_sector(editor);
	if (editor->sectors->point && (editor->sectors->point->x == point->x &&
	editor->sectors->point->y == point->y) && editor->sectors->vertices >= 3)
	{
		editor->sectors->is_closed = 1;
		printf("Sector created!\n");
	}
	else
	{
		if (editor->map[point->x / STEP][point->y / STEP] == 0)
		{
			editor->map[point->x / STEP][point->y / STEP] = 1;
			render_point(editor, point);
		}
		add_point(editor->sectors, point);
	}
}

int	set_point(SDL_Event event, t_editor *editor)
{
	t_point	*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		exit(EXIT_FAILURE);
	point->next = NULL;
	if (event.motion.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&point->x, &point->y);
			to_nearest_point(&point->x, &point->y);
			perform_sector(editor, point);
		}
	}
	return (0);
}