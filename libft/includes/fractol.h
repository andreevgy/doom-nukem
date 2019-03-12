/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:16:23 by marvin            #+#    #+#             */
/*   Updated: 2019/02/15 20:33:35 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H

# define FT_FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include <pthread.h>

# define W 1200
# define H 700
# define THREADS 10
# define NULL_CHECK(val) if (val == NULL) exit(12);

typedef struct	s_complex
{
	double	real;
	double	i;
}				t_complex;

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef	struct	s_fract
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_addr;
	int			size_line;
	t_pixel		color;
	double		zoom;
	int			move_julia;
	int			interface;
	int			updated;
	int			max_iters;
	int			pixels[H][W];
	int			julia;
	t_complex	julia_c;
	t_complex	move;
	int			(*calc)(t_pixel pixel, struct s_fract *fractal);
}				t_fract;

typedef struct	s_thread_args
{
	t_fract		*fract;
	t_pixel		start;
	t_pixel		end;
}				t_thread_args;

t_fract			*create_fractol(char *name);
void			*create_new_image(t_fract *fract);
void			set_pixel_to_image(char *data_addr,
										int size_line, t_pixel pixel);
void			get_data_addr(t_fract *fract);
void			draw_fract(t_fract *fract);
int				key_release(int keycode, void *param);
int				julia(t_pixel pixel, t_fract *fractal);
int				mandelbroot(t_pixel pixel, t_fract *fractal);
int				burningship(t_pixel pixel, t_fract *fractal);
int				mouse_release(int button, int x, int y, t_fract *fract);
int				key_press(int keycode, t_fract *fractol);
void			calculate_pixel(t_fract *fract, int (*calc)(t_pixel pixel,
				double zoom, int max_iters, t_complex *move), t_pixel pixel);
void			calculate_zone(t_fract *fractal, t_pixel start, t_pixel end);
void			*draw_threads(t_fract *fractal);
int				calculate_borders(t_fract *fr, t_pixel start, t_pixel end);
int				calculate_color(t_fract *fract, int i);
int				mouse_move(int x, int y, t_fract *fractal);
int				close_window(void *param);

#endif
