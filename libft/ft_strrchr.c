/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:10:06 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:44:34 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *lastocc;

	lastocc = NULL;
	while (*s)
	{
		if (*s == c)
			lastocc = (char*)s;
		s++;
	}
	if (!*s && c == '\0')
		return ((char *)s);
	return (lastocc);
}
