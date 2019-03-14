/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:16:23 by marvin            #+#    #+#             */
/*   Updated: 2019/03/14 14:52:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOM_H

# define FT_DOOM_H

# include <math.h>
# include <pthread.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"

# define MOVE_SPEED 0.25
# define RS 0.05
# define W 1600
# define H 1200
# define THREADS 10
# define NULL_CHECK(val) if (val == NULL) exit(12);
# define TS 64

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			tn;
	double		distance;
	t_pixel		draw_start;
	t_pixel		draw_end;
}				t_sprite;

typedef struct	s_doom
{
	SDL_Window	*window;
	SDL_Surface	*surface;
	SDL_Event	event;
	int			**map;
	int			running;
	int			vertical;
	SDL_Surface	*textures[9];
	SDL_Surface	*gun;
	Mix_Music	*music;
	t_sprite	sprites[4];
	double		z_buffer[W];
	int			changed;
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;
}				t_doom;

typedef struct	s_ray
{
	t_vector	camera;
	t_vector	dir;
	t_pixel		map;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_pixel		step;
	t_pixel		start_end;
	double		wall_x;
	int			tex_num;
	int			hit;
	int			side;
	double		wall_dist;
	int			lh;
}				t_ray;

typedef struct	s_thread_args
{
	t_doom		*doom;
	int			start;
	int			end;
}				t_thread_args;

t_doom			*create_doom(char *name);
int				key_press(SDL_Event event, t_doom *doom);
int				close_window(void *param);
int				read_map(t_doom **doom, char *name);
void			set_pixel_to_image(char *data_addr, int size_line,
t_pixel pixel);
void			get_data_addr(t_doom *doom);
void			draw_image(t_doom *doom);
void			rotate_right(t_doom **doom);
void			rotate_left(t_doom **doom);
void			move_forward(t_doom **doom);
void			move_back(t_doom **doom);
int				validate_map(t_doom *doom, t_pixel *size);
void			ray(t_doom *doom, int i);
int				read_textures(t_doom **doom);
void			floor_casting(t_ray ray, t_doom *doom, int x);
int				read_music(t_doom **doom);
void			*draw_threads(t_doom **doom);
void			*draw_sdl_threads(t_doom *doom);
void			draw_sprites(t_doom *doom);

#endif
