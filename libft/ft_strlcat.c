/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:47:27 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:41:28 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t len;
	size_t i;

	len = 0;
	while (s2[len])
		len++;
	i = 0;
	while (s1[i])
		i++;
	len += (i < n) ? i : n;
	while (n && *s2 && i < n - 1)
		s1[i++] = *s2++;
	if (i < n)
		s1[i] = '\0';
	return ((size_t)len);
}
