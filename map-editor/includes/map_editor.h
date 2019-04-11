/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:16:41 by ghalvors          #+#    #+#             */
/*   Updated: 2019/04/11 15:58:03 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"
#include "libft.h"

# define	W 2048
#define		H 1024

typedef struct	s_editor
{
	SDL_Window	*window;
	SDL_Surface	*surface;
	SDL_Event	event;
	int			running;
}				t_editor;


int	key_press(SDL_Event event, t_editor *editor);