/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:38:54 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/30 11:57:03 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_all *all, char **arr)
{
	int		*non_sort;
	int		*sort;
	int		i;
	int		len;
	int		num;

	len = 0;
	i = -1;
	while (arr[++i])
		len++;
	non_sort = malloc(sizeof(int) * (len));
	sort = malloc(sizeof(int) * (len));
	i = 0;
	while (i < len)
	{
		num = ft_atoi(arr[i]);
		non_sort[i] = num;
		sort[i] = num;
		i++;
	}
	bubble_sort(all, sort, non_sort, len);
}

void	bubble_sort(t_all *all, int *sort, int *non_sort, int len)
{
	int		i;
	int		j;
	int		tmp;
	int		count;
	
	i = 0;
	count = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1 - i))
		{
			if (sort[j] > sort[j + 1])
				{
					tmp = sort[j + 1];
					sort[j + 1] = sort[j];
					sort[j] = tmp;
					count++;
				}
			j++;
		}
		i++;
	}
	create_stack(all, sort, non_sort, len);
}

void	create_stack(t_all	*all, int *sort, int *non_sort, int len)
{
	int	i;
	int	j;
	
	i = 0;
	while(i < len)
	{	
		j = 0;
		while (j < len)
		{
			if (non_sort[i] == sort[j])
			{
				listadd(&all->stack_a, new_list(non_sort[i], j + 1));
				j++;
				break ;
			}
			j++;
		}
		i++;
	}
	free(non_sort);
	free(sort);
}