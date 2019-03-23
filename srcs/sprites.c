/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:31:21 by marvin            #+#    #+#             */
/*   Updated: 2019/03/23 17:07:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static	void	set_pixel(t_pixel pixel, t_doom *doom, Uint32 *color)
{
	if (*color != (unsigned int)-16777216)
		*(Uint32*)(doom->surface->pixels +
		((pixel.y + doom->vertical) * W + pixel.x)
		* doom->surface->format->BytesPerPixel) = *color;
}

static	void	draw_sprite(t_sprite sp,
t_vector transform, t_doom *doom)
{
	int		sp_screen_x;
	int		sp_heigth;
	int		sp_width;
	t_pixel	iter;
	t_pixel	tx;

	sp_screen_x = (int)((W / 2) * (1 + transform.x / transform.y));
	sp_heigth = abs((int)(H / (transform.y)));
	sp_width = sp_heigth;
	iter.x = sp.draw_start.x - 1;
	while (++iter.x < sp.draw_end.x)
		if (transform.y > 0 && iter.x > 0 && iter.x < W
		&& transform.y < doom->z_buffer[iter.x])
		{
			iter.y = sp.draw_start.y - 1;
			while (++iter.y < sp.draw_end.y)
			{
				tx.x = (int)((iter.x - (-sp_width / 2 + sp_screen_x))
				* TS / sp_width);
				tx.y = (((iter.y - H / 2 + sp_heigth / 2) * TS) / sp_heigth);
				set_pixel(iter, doom, doom->textures[sp.tn]->pixels + ((TS *
				tx.y + tx.x) * doom->textures[sp.tn]->format->BytesPerPixel));
			}
		}
}

static void		init_drawing_sprite(t_doom *doom, int i)
{
	t_vector	sprite;
	t_vector	tr;
	double		inv_det;
	int			h;

	sprite.x = doom->sprites[i].x - doom->pos.x;
	sprite.y = doom->sprites[i].y - doom->pos.y;
	inv_det = 1.0 / (doom->plane.x * doom->dir.y - doom->dir.x * doom->plane.y);
	tr.x = inv_det * (doom->dir.y * sprite.x - doom->dir.x * sprite.y);
	tr.y = inv_det * (-(doom->plane.y) * sprite.x + doom->plane.x * sprite.y);
	h = abs((int)(H / (tr.y)));
	doom->sprites[i].draw_start.y = -h / 2 + H / 2;
	if (doom->sprites[i].draw_start.y < 0)
		doom->sprites[i].draw_start.y = 0;
	doom->sprites[i].draw_end.y = h / 2 + H / 2;
	if (doom->sprites[i].draw_end.y >= H)
		doom->sprites[i].draw_end.y = H - 1;
	doom->sprites[i].draw_start.x = -h / 2 + (int)((W / 2) * (1 + tr.x / tr.y));
	if (doom->sprites[i].draw_start.x < 0)
		doom->sprites[i].draw_start.x = 0;
	doom->sprites[i].draw_end.x = h / 2 + (int)((W / 2) * (1 + tr.x / tr.y));
	if (doom->sprites[i].draw_end.x >= W)
		doom->sprites[i].draw_end.x = W - 1;
	draw_sprite(doom->sprites[i], tr, doom);
}

void			sort_sprites(t_doom *doom)
{
	int			i;
	int			k;
	t_sprite	temp;

	i = 0;
	while (i < doom->sprites_num)
	{
		k = 0;
		while (k < doom->sprites_num - 1)
		{
			if (doom->sprites[k].distance < doom->sprites[k + 1].distance)
			{
				temp = doom->sprites[k];
				doom->sprites[k] = doom->sprites[k + 1];
				doom->sprites[k + 1] = temp;
			}
			k++;
		}
		i++;
	}
}

void			draw_sprites(t_doom *doom)
{
	int	i;

	i = -1;
	while (++i < doom->sprites_num)
	{
		doom->sprites[i].distance = ((doom->pos.x - doom->sprites[i].x) *
		(doom->pos.x - doom->sprites[i].x) + (doom->pos.y - doom->sprites[i].y)
		* (doom->pos.y - doom->sprites[i].y));
	}
	sort_sprites(doom);
	i = -1;
	while (++i < doom->sprites_num)
		init_drawing_sprite(doom, i);
}
