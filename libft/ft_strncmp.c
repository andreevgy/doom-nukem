/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:33:28 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/11/28 08:20:00 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t i)
{
	size_t a;

	a = 0;
	if ((!*s2 && !*s1) || (!*s2 && !i) || (!i))
		return (0);
	if (!*s2)
		return (1);
	while ((*s1 == *s2) && *s1 && *s2 && a < i - 1)
	{
		s1++;
		s2++;
		a++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
