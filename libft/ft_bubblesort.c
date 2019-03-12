/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:04:46 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:08:27 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_bubblesort(int *arr, int length)
{
	int	tmp;
	int i;
	int k;

	i = 0;
	while (i < length)
	{
		k = 0;
		while (k < length - 1)
		{
			if (arr[k] > arr[k + 1])
			{
				tmp = arr[k + 1];
				arr[k + 1] = arr[k];
				arr[k] = tmp;
			}
			k++;
		}
		i++;
	}
	return (arr);
}
