/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:14:44 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:35:14 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*s2;
	char	*temp;

	length = ft_strlen(s1);
	s2 = (char*)malloc(sizeof(char) * (length + 1));
	if (!s2)
		return (NULL);
	temp = s2;
	while (*s1 && length--)
	{
		*s2 = *s1;
		s2++;
		s1++;
	}
	*s2 = '\0';
	return (temp);
}
