/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:58:48 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/02/21 17:10:54 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*
** trim
** Возвращает все до первого вхождения \n
*/

static int		trim(t_file *file, char **line)
{
	char	*start;
	int		i;
	char	*temp;

	i = 0;
	start = file->temp;
	if (*(file->temp) == '\n')
	{
		file->temp++;
		temp = ft_strdup(file->temp);
		file->temp = temp;
		ft_strdel(&start);
		*line = ft_strnew(0);
		return (1);
	}
	while (*(file->temp + i) != '\n' && *(file->temp + i))
		i++;
	file->temp = file->temp + i + 1;
	temp = ft_strdup(file->temp);
	file->temp = temp;
	temp = ft_strsub(start, 0, i);
	ft_strdel(&start);
	*line = temp;
	return (1);
}

/*
** create_file
** Создает новую структуру с переданным fd
*/

static t_file	*create_file(int fd)
{
	t_file *file;

	file = (t_file *)malloc(sizeof(t_file));
	file->fd = fd;
	file->read_res = 0;
	file->next = NULL;
	file->temp = ft_strnew(BUFF_SIZE + 1);
	return (file);
}

/*
** read_more
** Рекурсивно дочитывает в строку file->temp
*/

static void		read_more(t_file *file)
{
	char		*more_temp;
	char		*new_str;

	more_temp = ft_strnew(BUFF_SIZE + 1);
	file->read_res = read(file->fd, more_temp, BUFF_SIZE);
	new_str = ft_strjoin(file->temp, more_temp);
	ft_strdel(&more_temp);
	ft_strdel(&(file->temp));
	file->temp = new_str;
	if (!ft_strchr(file->temp, '\n') && file->read_res == BUFF_SIZE)
		read_more(file);
}

/*
** find_or_create_file
** Ищет или создает структуру в списке
*/

static	t_file	*find_or_create_file(t_file **list, int fd)
{
	t_file *file;
	t_file *iter;

	iter = *list;
	if (!list || !*list)
	{
		file = create_file(fd);
		*list = file;
	}
	else
	{
		if (iter->fd == fd)
			return (iter);
		while (iter->next)
		{
			if (iter->fd == fd)
				return (iter);
			iter = (iter)->next;
		}
		if ((iter)->fd == fd)
			return (iter);
		file = create_file(fd);
		iter->next = file;
	}
	return (file);
}

/*
** get_next_line
** Построчно читает в line из дескриптора fd
*/

int				get_next_line(const int fd, char **line)
{
	static t_file	*list = NULL;
	t_file			*file;

	if (fd < 0 || !line)
		return (-1);
	file = find_or_create_file(&list, fd);
	if (file->temp)
		if (ft_strchr(file->temp, '\n'))
			return (trim(file, line));
		else
			read_more(file);
	else
		file->read_res = read(fd, file->temp, BUFF_SIZE);
	if (file->read_res == -1)
		return (-1);
	if (!file->read_res && file->temp && *(file->temp))
	{
		*line = ft_strdup(file->temp);
		ft_strdel(&(file->temp));
		return (1);
	}
	if (!file->read_res)
		return (0);
	return (trim(file, line));
}
