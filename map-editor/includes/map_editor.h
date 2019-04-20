/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:16:41 by ghalvors          #+#    #+#             */
/*   Updated: 2019/04/20 14:33:21 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"
#include "libft.h"

# define	W 500
# define	H 500
# define	STEP 50

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}					t_point;

typedef struct	s_sector
{
	t_point			*point;
	t_point			*last_point;
	int				is_closed;
	int				vertices;
	struct s_sector	*next;
}				t_sector;

typedef struct	s_editor
{
	SDL_Window	*window;
	SDL_Surface	*surface;
	SDL_Event	event;
	char		map[100][100];
	t_sector	*sectors;
	int			running;
	int			move_x;
	int			move_y;
}				t_editor;

int	key_press(SDL_Event event, t_editor *editor);
int	set_point(SDL_Event event, t_editor *editor);