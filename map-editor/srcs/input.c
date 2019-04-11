/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:24:58 by ghalvors          #+#    #+#             */
/*   Updated: 2019/04/11 14:41:20 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_editor.h"

int	key_press(SDL_Event event, t_editor *editor)
{
	(void)event;
	if ((SDL_QUIT == editor->event.type) || (SDL_KEYDOWN == editor->event.type
			&& SDL_SCANCODE_ESCAPE == editor->event.key.keysym.scancode))
		editor->running = 0;
	return (0);
}
