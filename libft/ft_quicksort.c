/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:13:52 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:39:11 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

static int	choose_pivot(int i, int j)
{
	return ((i + j) / 2);
}

void		ft_quicksort(int list[], int m, int n)
{
	int key;
	int i;
	int j;
	int k;

	if (m < n)
	{
		k = choose_pivot(m, n);
		swap(&list[m], &list[k]);
		key = list[m];
		i = m + 1;
		j = n;
		while (i <= j)
		{
			while ((i <= n) && (list[i] <= key))
				i++;
			while ((j >= m) && (list[j] > key))
				j--;
			if (i < j)
				swap(&list[i], &list[j]);
		}
		swap(&list[m], &list[j]);
		ft_quicksort(list, m, j - 1);
		ft_quicksort(list, j + 1, n);
	}
}
