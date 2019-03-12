/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:55:58 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:47:03 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*newstr;
	int		start;
	int		length;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	length = ft_strlen(s);
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	start = i;
	while (s[length - 1] == ' ' || s[length - 1] == '\t' ||
			s[length - 1] == '\n')
		length--;
	length -= i;
	if (length <= 0)
		length = 0;
	newstr = ft_strsub(s, start, length);
	if (!newstr)
		return (NULL);
	return (newstr);
}
