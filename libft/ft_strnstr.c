/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:09:53 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/28 22:07:53 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	n;

	n = 0;
	if (!*needle)
		return ((char*)haystack);
	while (*haystack && n < len)
	{
		i = 0;
		if (haystack[i] == needle[i])
		{
			while (needle[i] && n + i < len)
			{
				if (needle[i] != haystack[i])
					break ;
				i++;
			}
			if (!needle[i])
				return ((char*)haystack);
		}
		n++;
		haystack++;
	}
	return (NULL);
}
