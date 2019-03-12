/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:33:39 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/12 11:54:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static t_pixel	*create_pixel(int x, int y)
{
	t_pixel	*pixel;

	pixel = (t_pixel *)ft_memalloc(sizeof(t_pixel));
	pixel->x = x;
	pixel->y = y;
	return (pixel);
}

static t_pixel	*read_size(int fd)
{
	t_pixel	*size;
	char	*line;
	char	**split;

	get_next_line(fd, &line);
	split = ft_strsplit(line, ',');
	if (split[0] && split[1])
	{
		size = create_pixel(ft_atoi(split[0]), ft_atoi(split[1]));
		if (size->x <= 0 || size->y <= 0)
			return (NULL);
		return (size);
	}
	return (NULL);
}

static int		malloc_map(t_doom *doom, t_pixel *size)
{
	int i;

	doom->map = (int **)ft_memalloc(sizeof(int *) * size->y);
	if (doom->map == NULL)
		return (0);
	i = 0;
	while (i < size->y)
	{
		doom->map[i] = (int *)ft_memalloc(sizeof(int) * size->x);
		if (doom->map[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

static int		fill_map(t_doom *doom, int fd, t_pixel *size)
{
	char	*line;
	t_pixel	iter;
	char	**split;

	iter.y = 0;
	while (iter.y < size->y)
	{
		if (!get_next_line(fd, &line))
			return (0);
		iter.x = 0;
		split = ft_strsplit(line, ' ');
		while (iter.x < size->x)
		{
			if (!split[iter.x])
				return (0);
			doom->map[iter.y][iter.x] = ft_atoi(split[iter.x]);
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
	t_pixel	*size;

	fd = open(name, O_RDONLY);
	size = read_size(fd);
	if (!size || !malloc_map(*doom, size) || !fill_map(*doom, fd, size)
				|| !validate_map(*doom, size))
		return (0);
	return (1);
}
