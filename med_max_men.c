/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_max_men.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:25:41 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/04 11:03:14 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	med_min_max(t_all *all)
{
	int	i;
	int	min;
	int	max;
	t_node	*tmp;

	tmp = all->stack_a;
	if (all->size_a == 0)
		return ;
	i = all->size_a;
	min = all->stack_a->index;
	max = all->stack_a->index;
	while (i-- > 0)
	{
		if (min > all->stack_a->index)
			min = all->stack_a->index;
		if (max < all->stack_a->index)
			max = all->stack_a->index;
		all->stack_a = all->stack_a->next;
	}
	all->min = min;
	all->max = max;
	all->med = (min + max) / 2;
	all->stack_a = tmp;
}

int sort_true(t_all *all)
{
	int		i;
	t_node	*tmp;

	tmp = all->stack_a;
	i = all->size_a - 1;
	while (i--)
	{
		if (tmp->index > tmp->next->index)
			return(0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_stack(t_all *all)
{
	t_node		*tmp;
	
	while (all->size_a--)
	{
		tmp = all->stack_a->next;
		free(all->stack_a);
		all->stack_a = NULL;
		all->stack_a = tmp;
	}
	while (all->size_b)
	{
		tmp = all->stack_b->next;
		free(all->stack_b);
		all->stack_b = NULL;
		all->stack_b = tmp;
	}
	free(all);
	exit(0);
}

void	push_down(t_all *all, int flag)
{
	all->stack_a->flag = -1;
	ra(all, 1);
	if (flag)
		printf("PUSH_DOWN\n");
}