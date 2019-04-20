/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_modal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:26:56 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/04/20 17:22:27 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Компилить: gcc create_modal.c -I ../includes -I ../../includes -L/Users/fmacgyve/.brew/lib -lSDL2 -lSDL2_ttf -I/Users/fmacgyve/.brew/include/SDL2 -D_THREAD_SAFE ../../libft/libft.a

#include "map_editor.h"

typedef struct	s_modal_data
{
	int			floor_height;
	int			ceil_height;
	int			active_field;
	char		*input_text[2];
}				t_modal_data;

TTF_Font *font = NULL;


void	put_pixel(SDL_Surface *surface, t_point point)
{
		*(Uint32*)(surface->pixels + ((point.y) * 400 + point.x)
		* surface->format->BytesPerPixel) = 0xFFFFFFFF;
}

void	draw_text(SDL_Surface *surface, char *text, t_point pos)
{
	SDL_Color text_color = (SDL_Color){ 255, 255, 255, 1 };
	SDL_Surface *message = TTF_RenderText_Solid( font, text, text_color);
    SDL_Rect offset;

    //Get offsets
    offset.x = pos.x;
    offset.y = pos.y;

    //Blit
    SDL_BlitSurface( message, NULL, surface, &offset );
}

void	draw_input_rectangle(SDL_Surface *surface, t_point start, t_point end)
{
	t_point iter;

	iter.x = start.x;
	iter.y = start.y;
	while (iter.x < end.x)
	{
		put_pixel(surface, iter);
		iter.x++;
	}
	while (iter.y < end.y)
	{
		put_pixel(surface, iter);
		iter.y++;
	}
	while (iter.x > start.x)
	{
		put_pixel(surface, iter);
		iter.x--;
	}
	while (iter.y > start.y)
	{
		put_pixel(surface, iter);
		iter.y--;
	}
}

void	draw_data(SDL_Surface *surface, SDL_Window *window, t_modal_data data)
{
	t_point start;
	t_point end;

	start.x = 10;
	start.y = 10;
	end.x = 390;
	end.y = 50;
	SDL_FillRect(surface, NULL, 0x000000);
	draw_input_rectangle(surface, start, end);
	start.x = 20;
	draw_text(surface, data.input_text[0], start);
	start.x = 10;
	start.y = 60;
	end.y = 100;
	draw_input_rectangle(surface, start, end);
	start.x = 20;
	draw_text(surface, data.input_text[1], start);
	SDL_UpdateWindowSurface(window);
}

void	create_modal()
{
	// TODO оптимизировать и доделать
	SDL_Window *window = SDL_CreateWindow("modal", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, 400, 500, SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_StartTextInput();
	TTF_Init();
	font = TTF_OpenFont("./font.ttf", 28);
	SDL_Surface *surface = SDL_GetWindowSurface(window);
	t_modal_data data;
	data.active_field = 0;
	data.input_text[0] = ft_strnew(0);
	data.input_text[1] = ft_strnew(0);
	int done = 0;
	draw_data(surface, window, data);
	while(!done)
	{
		draw_data(surface, window, data);
		SDL_UpdateWindowSurface(window);
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			switch (event.type) {
				case SDL_QUIT:
					/* Quit */
					done = SDL_TRUE;
					break;
				case SDL_TEXTINPUT:
					/* Add new text onto the end of our text */
					if (((ft_atoi(data.input_text[data.active_field]) >= 0 && ft_strlen(data.input_text[data.active_field]) < 10) ||
					(ft_atoi(data.input_text[data.active_field]) < 0 && ft_strlen(data.input_text[data.active_field]) < 11)) &&
					((*event.text.text == '-' &&
					!ft_strlen(data.input_text[data.active_field]))
					|| ft_isdigit(*event.text.text)))
					{
						strcat(data.input_text[data.active_field], event.text.text);
						printf("%s\n", data.input_text[data.active_field]);
						printf("%d\n", ft_atoi(data.input_text[data.active_field]));
					}
					break;
				case SDL_TEXTEDITING:
					/*
					Update the composition text.
					Update the cursor position.
					Update the selection length (if any).
					*/
					break;
				case SDL_KEYDOWN:
					if (event.key.keysym.scancode == SDL_SCANCODE_DOWN && data.active_field != 1)
						data.active_field++;
					if (event.key.keysym.scancode == SDL_SCANCODE_UP && data.active_field != 0)
						data.active_field--;

			}
		}
	}
}

int main(void)
{
	create_modal();
	return (0);
}
