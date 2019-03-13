/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:28:03 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/13 12:49:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
**	get_texture
**	Returns number of texture depending on side of wall and direction
*/

static int	get_texture(int side, t_vector dir)
{
	if (side == 0 && dir.x > 0)
		return (0);
	else if (side == 0 && dir.x < 0)
		return (1);
	else if (side == 1 && dir.y > 0)
		return (2);
	else
		return (3);
}

/*
**	draw_line
**	Draws one vertical line of wall depending on ray info and x-coordinate
*/

static void	draw_line(t_ray ray, t_doom *doom, int x)
{
	t_pixel	pixel;
	t_pixel	t;

	pixel.x = x;
	pixel.y = ray.start_end.x - 1 > 0 ? ray.start_end.x - 1 : 0;
	ray.tex_num = get_texture(ray.side, ray.dir);
	if (ray.side == 0)
		ray.wall_x = doom->pos.y + ray.wall_dist * ray.dir.y;
	else
		ray.wall_x = doom->pos.x + ray.wall_dist * ray.dir.x;
	ray.wall_x -= floor((ray.wall_x));
	t.x = (int)(ray.wall_x * (double)TS);
	if (ray.side == 0 && ray.dir.x > 0)
		t.x = TS - t.x - 1;
	if (ray.side == 1 && ray.dir.y < 0)
		t.x = TS - t.x - 1;
	while (++pixel.y < ray.start_end.y)
		if (pixel.y < H && pixel.x < W)
			*(Uint32*)(doom->surface->pixels + ((pixel.y) * W + pixel.x)
			* doom->surface->format->BytesPerPixel) =
			*(Uint32*)(doom->textures[ray.tex_num]->pixels + (TS
			* (((pixel.y - ray.start_end.x) * TS) / ray.lh) + t.x)
			* doom->textures[ray.tex_num]->format->BytesPerPixel);
	floor_casting(ray, doom, x);
}

/*
**	init_ray
**	Calculate starting values for ray
*/

static void	init_ray(t_ray *ray, t_vector pos, t_vector dir, t_vector plane)
{
	ray->dir.x = dir.x + plane.x * ray->camera.x;
	ray->dir.y = dir.y + plane.y * ray->camera.x;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - pos.y) * ray->delta_dist.y;
	}
	ray->hit = 0;
}

/*
**	move_ray
**	Moves ray depending on side
*/

static void	move_ray(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map.x += ray->step.x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map.y += ray->step.y;
		ray->side = 1;
	}
}

/*
**	ray
**	Creates ray and casts in right direction, then draws a wall
*/

void		ray(t_doom *doom, int i)
{
	t_ray ray;

	ray.map.x = (int)doom->pos.x;
	ray.map.y = (int)doom->pos.y;
	ray.camera.x = 2 * i / (double)W - 1;
	init_ray(&ray, doom->pos, doom->dir, doom->plane);
	while (ray.hit == 0)
	{
		move_ray(&ray);
		if (doom->map[ray.map.y][ray.map.x] != 0)
			ray.hit = 1;
	}
	if (ray.side == 0)
		ray.wall_dist = (ray.map.x - doom->pos.x
							+ (1 - ray.step.x) / 2) / ray.dir.x;
	else
		ray.wall_dist = (ray.map.y - doom->pos.y
							+ (1 - ray.step.y) / 2) / ray.dir.y;
	ray.lh = abs((int)(H / ray.wall_dist));
	ray.start_end.x = (-ray.lh / 2 + H / 2 + doom->vertical);
	ray.start_end.y = (ray.lh / 2 + H / 2 + doom->vertical);
	draw_line(ray, doom, i);
}
