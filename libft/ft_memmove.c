/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:01:12 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:21:57 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*src_copy;
	char	*dst_copy;
	size_t	i;
	int		intn;

	i = 0;
	intn = (int)n;
	src_copy = (char *)src;
	dst_copy = (char *)dst;
	if (src_copy < dst_copy)
		while (--intn >= 0)
			dst_copy[intn] = src_copy[intn];
	else
		while (i < n)
		{
			dst_copy[i] = src_copy[i];
			i++;
		}
	return (dst);
}
