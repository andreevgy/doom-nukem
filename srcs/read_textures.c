/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:17:36 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/13 16:24:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static SDL_Surface	*create_surface(int width, int heigth)
{
	SDL_Surface	*surface;
	Uint32		rmask;
	Uint32		gmask;
	Uint32		bmask;
	Uint32		amask;

	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
	surface = SDL_CreateRGBSurface(0, width, heigth, 32,
									rmask, gmask, bmask, amask);
	return (surface);
}

static void			set_pixel(SDL_Surface *gun, SDL_Surface *new_gun,
						t_pixel gi, t_pixel *ngi)
{
	*(Uint32*)(new_gun->pixels + (ngi->y * 128 * 4 + ngi->x)
	* new_gun->format->BytesPerPixel) = *(Uint32*)(gun->pixels
	+ (gi.y * 128 + gi.x) * new_gun->format->BytesPerPixel);
	ngi->x++;
}

static SDL_Surface	*resize_gun(SDL_Surface *gun)
{
	SDL_Surface	*new_gun;
	t_pixel		gi;
	t_pixel		ngi;
	t_pixel		iter_zoom;

	new_gun = create_surface(512, 512);
	gi.y = -1;
	ngi.y = 0;
	while (++gi.y < 128)
	{
		iter_zoom.y = -1;
		while (++iter_zoom.y < 4)
		{
			gi.x = -1;
			ngi.x = 0;
			while (++gi.x < 128)
			{
				iter_zoom.x = -1;
				while (++iter_zoom.x < 4)
					set_pixel(gun, new_gun, gi, &ngi);
			}
			ngi.y++;
		}
	}
	return (new_gun);
}

static int			load_texture(t_doom **doom, int i, char *name)
{
	SDL_RWops *ops;

	ops = SDL_RWFromFile(name, "rb");
	if (!ops)
		return (0);
	(*doom)->textures[i] = IMG_Load_RW(ops, 1);
	if (!((*doom)->textures[i]) || (*doom)->textures[i]->w != TS
		|| (*doom)->textures[i]->h != TS)
		return (0);
	return (1);
}

int					read_textures(t_doom **doom)
{
	SDL_Surface *gun;

	if (!load_texture(doom, 0, "assets/textures/colorstone.png") ||
	!load_texture(doom, 1, "assets/textures/bluestone.png") ||
	!load_texture(doom, 2, "assets/textures/mossy.png") ||
	!load_texture(doom, 3, "assets/textures/redbrick.png") ||
	!load_texture(doom, 4, "assets/textures/greystone.png") ||
	!load_texture(doom, 5, "assets/textures/wood.png") ||
	!load_texture(doom, 6, "assets/textures/pillar.png") ||
	!load_texture(doom, 7, "assets/textures/barrel.png") ||
	!load_texture(doom, 8, "assets/textures/greenlight.png"))
		return (0);
	gun = IMG_Load_RW(
		SDL_RWFromFile("assets/textures/gun.png", "rb"), 1);
	if (!((*doom)->textures[0]) || !((*doom)->textures[1]) ||
		!((*doom)->textures[2]) || !((*doom)->textures[3]) ||
		!((*doom)->textures[4]) || !((*doom)->textures[5]) ||
		!((*doom)->textures[6]) || !((*doom)->textures[7]) ||
		!((*doom)->textures[8]) || !gun)
		return (0);
	(*doom)->gun = resize_gun(gun);
	return (1);
}
