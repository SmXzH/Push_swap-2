/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:59:34 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/08 21:45:56 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tree_a(t_all *all)
{
	int	a;
	int	b;
	int	c;

	a = all->stack_a->index;
	b = all->stack_a->next->index;
	c = all->stack_a->next->next->index;
	if (b > c && b > a)
		rra(all, 1);
	else if (a > b && a > c)
		ra(all, 1);
	a = all->stack_a->index;
	b = all->stack_a->next->index;
	if (a > b)
		sa(all, 1);
}

void	sort_five(t_all *all)
{
	if (all->size_a == 5)
	{
		while (all->size_a > 3)
		{
			med_min_max(all);
			if (all->stack_a->index == all->min)
			{
				pb(all, 1);
			}
			else
				rra(all, 1);
		}
		sort_tree_a(all);
		pa(all, 1);
		pa(all, 1);
	}
	if (all->size_a == 4)
		sort_four(all);
	else if (all->size_a < 4)
		sort_tree_a(all);
}

void	sort_four(t_all *all)
{
	if (all->size_a == 4)
	{
		while (all->size_a > 3)
		{
			med_min_max(all);
			if (all->stack_a->index == all->min)
			{
				pb(all, 1);
			}
			else
				rra(all, 1);
		}
		sort_tree_a(all);
		pa(all, 1);
	}
}
