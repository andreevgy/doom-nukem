/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:33:39 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/31 12:34:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int		read_size(int fd, int *x, int *y)
{
	char	*line;
	char	**split;

	get_next_line(fd, &line);
	split = ft_strsplit(line, ',');
	if (split[0] && split[1])
	{
		*x = ft_atoi(split[0]);
		*y = ft_atoi(split[1]);
		if (*x <= 0 || *y <= 0)
			return (0);
		return (1);
	}
	return (0);
}

static int		malloc_map(t_doom *doom, t_pixel size)
{
	int i;

	doom->map = (t_block ***)ft_memalloc(sizeof(t_block **) * size.y);
	if (doom->map == NULL)
		return (0);
	i = 0;
	while (i < size.y)
	{
		doom->map[i] = (t_block **)ft_memalloc(sizeof(t_block *) * size.x);
		if (doom->map[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

static void		split_commas(t_doom *doom, t_pixel it, char *split)
{
	char	**new_split;
	double	height;

	new_split = ft_strsplit(split, ',');
	height = (double)ft_atoi(new_split[1]) / 10;
	doom->map[it.y][it.x] = create_block(height, ft_atoi(new_split[0]));
}

static int		fill_map(t_doom *doom, int fd, t_pixel size)
{
	char	*line;
	t_pixel	iter;
	char	**split;

	iter.y = 0;
	while (iter.y < size.y)
	{
		if (!get_next_line(fd, &line))
			return (0);
		iter.x = 0;
		split = ft_strsplit(line, ' ');
		while (iter.x < size.x)
		{
			if (!split[iter.x])
				return (0);
			split_commas(doom, iter, split[iter.x]);
			iter.x++;
		}
		iter.y++;
	}
	return (1);
}

/*
**	read_map
**	Reads map from file
*/

int				read_map(t_doom **doom, char *name)
{
	int		fd;
	int		x;
	int		y;
	t_pixel	size;

	size.x = 0;
	size.y = 0;
	fd = open(name, O_RDONLY);
	if (!read_size(fd, &x, &y))
		return (0);
	size.x = x;
	size.y = y;
	(*doom)->size = size;
	if (!size.x || !malloc_map(*doom, size) || !fill_map(*doom, fd, size)
				|| !validate_map(*doom, size))
		return (0);
	return (1);
}
