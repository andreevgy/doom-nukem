/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:58:55 by marvin            #+#    #+#             */
/*   Updated: 2019/03/23 16:59:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static t_thread_args	*create_args(t_doom *doom, int start, int end)
{
	t_thread_args *args;

	NULL_CHECK((args = ft_memalloc(sizeof(t_thread_args))));
	args->doom = doom;
	args->start = start;
	args->end = end;
	return (args);
}

static int				draw_rays_thread(void *param)
{
	int				i;
	t_thread_args	*args;

	args = (t_thread_args*)param;
	i = args->start;
	while (i < args->end)
	{
		ray(args->doom, i);
		i++;
	}
	return (0);
}

static void				draw_gun(t_doom *doom)
{
	t_pixel	iw;
	t_pixel	it;
	Uint32	tr;

	tr = *(Uint32*)doom->gun->pixels + (0 * 384 + 0)
			* doom->surface->format->BytesPerPixel;
	it.y = -1;
	iw.y = H - 384;
	while (++it.y < 384)
	{
		it.x = -1;
		iw.x = W / 2 - 192;
		while (++it.x < 384)
		{
			if (tr != *(Uint32*)(doom->gun->pixels + (it.y * 384 + it.x)
			* doom->surface->format->BytesPerPixel))
				*(Uint32*)(doom->surface->pixels + (iw.y * W + iw.x)
				* doom->surface->format->BytesPerPixel) = *(Uint32*)
				(doom->gun->pixels + (it.y * 384 + it.x)
				* doom->surface->format->BytesPerPixel);
			iw.x++;
		}
		iw.y++;
	}
}

/*
**	void					*draw_threads(t_doom **doom)
**	{
**	t_thread_args	*args;
**	int				start;
**	int				end;
**	pthread_t		id_arr[THREADS];
**	int				i;
**	i = -1;
**	start = 0;
**	end = W / THREADS;
**	while (++i < THREADS)
**	{
**		args = create_args(*doom, start, end);
**		pthread_create(&(id_arr[i]), NULL, &draw_rays_thread, args);
**		start = end;
**		end = end + W / THREADS;
**	}
**	i = -1;
**	while (++i < THREADS)
**		pthread_join(id_arr[i], NULL);
**	draw_gun(*doom);
**	SDL_UpdateWindowSurface((*doom)->window);
**	(*doom)->changed = 0;
**	return (NULL);
**	}
*/

void					init_and_draw_threads(t_doom *doom)
{
	t_thread_args	*args[THREADS];
	int				start;
	int				end;
	SDL_Thread		*id_arr[THREADS];
	int				i;

	i = -1;
	start = 0;
	end = W / THREADS;
	while (++i < THREADS)
	{
		args[i] = create_args(doom, start, end);
		id_arr[i] = SDL_CreateThread(draw_rays_thread, NULL, args[i]);
		start = end;
		end = end + W / THREADS;
	}
	i = -1;
	while (++i < THREADS)
	{
		SDL_WaitThread(id_arr[i], NULL);
		free(args[i]);
	}
}

void					*draw_sdl_threads(t_doom *doom)
{
	init_and_draw_threads(doom);
	draw_sprites(doom);
	draw_gun(doom);
	SDL_UpdateWindowSurface(doom->window);
	doom->changed = 0;
	return (NULL);
}
