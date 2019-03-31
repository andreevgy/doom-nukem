/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:21:15 by marvin            #+#    #+#             */
/*   Updated: 2019/03/31 13:34:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
**	get_height_and_texture
**	Gets needed data from texture and calculates ray->start_end
*/

static void		get_height_and_texture(t_ray *ray, t_doom *doom)
{
	int	height;

	ray->lh = abs((int)((H / ray->wall_dist)));
	height = ray->lh * doom->map[ray->map.y][ray->map.x]->height;
	ray->tex_num = doom->map[ray->map.y][ray->map.x]->texture;
	ray->start_end.x = (-height / 2 + H / 2 + doom->vertical)
		+ (ray->lh - height) / 2;
	ray->start_end.y = (height / 2 + H / 2 + doom->vertical)
		+ (ray->lh - height) / 2;
}

/*
**	draw_small_wall_ceil
**	Draws ceil of small wall after drawing wall iteself
*/

static void		draw_small_wall_ceil(t_ray *ray, t_doom *doom, int x)
{
	t_ray	tmp;
	int		height;
	t_pixel	pixel;

	tmp = *ray;
	move_ray(&tmp);
	calculate(&tmp, doom);
	tmp.lh = abs((int)((H / tmp.wall_dist)));
	height = tmp.lh * doom->map[ray->map.y][ray->map.x]->height;
	tmp.start_end.x = (-height / 2 + H / 2 + doom->vertical)
		+ (tmp.lh - height) / 2;
	tmp.start_end.y = (height / 2 + H / 2 + doom->vertical)
		+ (tmp.lh - height) / 2;
	pixel.y = tmp.start_end.x - 1 > 0 ? tmp.start_end.x - 1 : 0;
	pixel.x = x;
	while (++pixel.y < ray->start_end.x)
		if (pixel.y < H && pixel.x < W
		&& pixel.y >= 0 && pixel.x >= 0 && pixel.y < tmp.max_y)
			*(Uint32*)(doom->surface->pixels + ((pixel.y) * W + pixel.x)
			* doom->surface->format->BytesPerPixel) = 0x00FF00;
	ray->max_y = tmp.start_end.x < tmp.max_y ? tmp.start_end.x : tmp.max_y;
}

/*
**	draw_small_wall
**	Draws small wall depending on ray info and height
*/

void			draw_small_wall(t_ray *ray, t_doom *doom, int x)
{
	t_pixel	pixel;
	t_pixel	t;

	get_height_and_texture(ray, doom);
	pixel.x = x;
	pixel.y = ray->start_end.x - 1 > 0 ? ray->start_end.x - 1 : 0;
	ray->wall_x = ray->side == 0 ? doom->pos.y + ray->wall_dist * ray->dir.y
				: doom->pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor((ray->wall_x));
	t.x = (int)(ray->wall_x * (double)TS);
	t.x = (ray->side == 0 && ray->dir.x) > 0
		|| (ray->side == 1 && ray->dir.y < 0) ? TS - t.x - 1 : t.x;
	while (++pixel.y < ray->start_end.y)
		if (pixel.y < H && pixel.x < W &&
		pixel.y >= 0 && pixel.x >= 0 && pixel.y < ray->max_y)
			*(Uint32*)(doom->surface->pixels + ((pixel.y) * W + pixel.x)
			* doom->surface->format->BytesPerPixel) =
			*(Uint32*)(doom->textures[ray->tex_num]->pixels + (TS
			* (((pixel.y - ray->start_end.x) * TS) / ray->lh) + t.x)
			* doom->textures[ray->tex_num]->format->BytesPerPixel);
	draw_small_wall_ceil(ray, doom, x);
	ray->max_y = ray->start_end.x < ray->max_y ? ray->start_end.x : ray->max_y;
}
