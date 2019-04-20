x/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:10:01 by marvin            #+#    #+#             */
/*   Updated: 2019/03/28 23:35:53 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		define_side(t_ray ray, t_vector *floor_wall)
{
	if (ray.side == 0 && ray.dir.x > 0)
	{
		floor_wall->x = ray.map.x;
		floor_wall->y = ray.map.y + ray.wall_x;
	}
	else if (ray.side == 0 && ray.dir.x <= 0)
	{
		floor_wall->x = ray.map.x + 1.0;
		floor_wall->y = ray.map.y + ray.wall_x;
	}
	else if (ray.side == 1 && ray.dir.y > 0)
	{
		floor_wall->x = ray.map.x + ray.wall_x;
		floor_wall->y = ray.map.y;
	}
	else
	{
		floor_wall->x = ray.map.x + ray.wall_x;
		floor_wall->y = ray.map.y + 1.0;
	}
}

static void		draw_pixel(t_ray ray, t_doom *doom,
							t_pixel pixel, t_vector floor_wall)
{
	double		current_dist;
	double		weigth;
	t_vector	current_floor;
	t_pixel		floor_tex;

	current_dist = H / (2.0 * pixel.y - H - 2 * doom->vertical);
	weigth = current_dist / ray.wall_dist;
	current_floor.x = weigth * floor_wall.x + (1.0 - weigth) * doom->pos.x;
	current_floor.y = weigth * floor_wall.y + (1.0 - weigth) * doom->pos.y;
	floor_tex.x = (int)(current_floor.x * TS) % TS;
	floor_tex.y = (int)(current_floor.y * TS) % TS;
	if (pixel.y < H && pixel.x < W)
		*(Uint32*)(doom->surface->pixels + ((pixel.y) * W + pixel.x)
		* doom->surface->format->BytesPerPixel) =
		*(Uint32*)(doom->textures[4]->pixels + (TS * floor_tex.y + floor_tex.x)
		* doom->textures[4]->format->BytesPerPixel);
	if ((H + (2 * doom->vertical) - pixel.y) < H
	&& (H + (2 * doom->vertical) - pixel.y) >= 0 && pixel.x >= 0 && pixel.x < W)
		*(Uint32*)(doom->surface->pixels + ((H + (2 * doom->vertical) - pixel.y)
		* W + pixel.x)
		* doom->surface->format->BytesPerPixel) =
		*(Uint32*)(doom->textures[5]->pixels + (TS * floor_tex.y + floor_tex.x)
		* doom->textures[5]->format->BytesPerPixel);
}

void			floor_casting(t_ray ray, t_doom *doom, int x)
{
	t_vector	floor_wall;
	t_pixel		pixel;

	define_side(ray, &floor_wall);
	if (ray.start_end.y < 0)
		ray.start_end.y = H;
	pixel.y = ray.start_end.y + 1;
	pixel.x = x;
	while (pixel.y < H + 2 * abs(doom->vertical))
	{
		draw_pixel(ray, doom, pixel, floor_wall);
		pixel.y++;
	}
}
