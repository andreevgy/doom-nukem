/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:09:53 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:46:08 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		i = 0;
		if (haystack[i] == needle[i])
		{
			while (needle[i])
			{
				if (needle[i] != haystack[i])
					break ;
				i++;
			}
			if (!needle[i])
				return ((char*)haystack);
		}
		haystack++;
	}
	return (NULL);
}
