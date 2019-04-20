/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_modal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <hkuphal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:26:56 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/04/20 14:38:09 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_editor.h"

typedef struct	s_modal_data
{
	int			floor_height;
	int			ceil_height;
	int			active_field;
	char		*input_text[2];
}				t_modal_data;

// void    draw_input_rectangle(SDL_Surface *surface)
// {

// }

void	create_modal()
{
	SDL_CreateWindow("modal", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, 400, 500, SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_StartTextInput();
	t_modal_data data;
	data.active_field = 0;
	data.input_text[0] = ft_strnew(0);
	data.input_text[1] = ft_strnew(0);
	int done = 0;
	while(!done)
	{
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
					if (ft_isdigit(*event.text.text))
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
