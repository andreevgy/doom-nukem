/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:50:14 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 16:45:19 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			min;
	long long	prev;
	long long	number;

	number = 0;
	min = 1;
	i = 0;
	while (str[i] == '\r' || str[i] == '\f' || str[i] == '\n' || str[i] == ' '
	|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			min = -1;
	while (ft_isdigit(str[i]))
	{
		prev = number;
		number = number * 10 + (str[i++] - '0');
		if (number < prev)
			return ((min == 1) ? (-1) : (0));
	}
	return (number * min);
}
