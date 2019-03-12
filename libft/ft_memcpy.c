/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:39:50 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:15:49 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*dest_copy;
	const char	*src_copy;

	i = 0;
	dest_copy = dest;
	src_copy = src;
	while (i++ < (int)n)
		*(dest_copy++) = *(src_copy++);
	return (dest);
}
