/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:21:12 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/05 17:31:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void	create_vertical_border(int width, int fd)
{
	int i;

	i = 0;
	ft_putnbr_fd(1, fd);
	while (i < width - 1)
	{
		ft_putstr_fd(" 1", fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

void	inside_lines(int width, int heigth, int space, int fd)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	srand(time(NULL));
	pos_x = rand() % width;
	pos_y = rand() % heigth;
	y = -1;
	while (++y < heigth - 2)
	{
		x = -1;
		ft_putnbr_fd(1, fd);
		while (++x < width - 2)
		{
			ft_putchar_fd(' ', fd);
			if (x == pos_x && y == pos_y)
				ft_putnbr_fd(-1, fd);
			else
				ft_putnbr_fd(rand() % space == 0 ? 1 : 0, fd);
		}
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(1, fd);
		ft_putchar_fd('\n', fd);
	}
}

int		main(int argc, char **argv)
{
	int	fd;
	int	width;
	int	height;
	int space;

	if (argc == 5)
	{
		width = ft_atoi(argv[2]);
		height = ft_atoi(argv[3]);
		space = ft_atoi(argv[4]);
		fd = open(ft_strcat(argv[1], ".wolf"), O_WRONLY | O_CREAT, 777);
		ft_putnbr_fd(width, fd);
		ft_putchar_fd(',', fd);
		ft_putnbr_fd(height, fd);
		ft_putchar_fd('\n', fd);
		create_vertical_border(width, fd);
		inside_lines(width, height, space, fd);
		create_vertical_border(width, fd);
		close(fd);
	}
	else
		ft_putstr("usage: ./mapgen <filename> <heigth> <width> <space>\n");
}
