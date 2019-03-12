/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:45:22 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:15:59 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *dest_copy;
	unsigned char *src_copy;
	unsigned char c_copy;

	if (!n || dest == src)
		return (NULL);
	dest_copy = (unsigned char *)dest;
	src_copy = (unsigned char *)src;
	c_copy = (unsigned char)c;
	while (n--)
	{
		*dest_copy = *src_copy;
		if (*dest_copy == c_copy)
			return (dest_copy + 1);
		dest_copy++;
		src_copy++;
	}
	return (NULL);
}
