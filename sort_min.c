/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:59:34 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/04 16:03:42 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tree_a(t_all *all)
{
	int	a;
	int b;
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

void	sort_five_b_to_a(t_all *all)
{
	int		index_last;
	int		min;
	int		flag;
	int		i;
	t_node	*tmp;

	i = all->size_b;
	flag = all->stack_a->flag;
	tmp = all->stack_a;
	while(tmp->next != NULL)
		tmp = tmp->next;
	index_last = tmp->index;
	min = tmp->index + 1;
	tmp = all->stack_a;
	while (i > 3)
	{
		if (all->stack_b->index == min)
		{
			pa(all, 1);
			push_down(all, 1);
			min++;
		}
		else
			pa(all, 1);
		i--;
	}
	sort_a_to_b(all);
	if (all->stack_a->index > all->stack_a->next->index && all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || all->stack_a->flag == -1)
		{
			pa(all, 1);
			printf("HAHAHAHAHAHHAHAHAHHAHAHHAHAHHAHAHAHHA\n");
			push_down(all, 1);
		}
		else
			push_down(all, 1);
	}
	while (all->stack_a->flag == flag && flag != -1 && all->stack_a->index + 1 == index_last)
		push_down(all, 1);
	
}
void	sort_a_to_b(t_all *all)
{
	int	a;
	int	b;
	int	c;

	if (all->size_b == 0)
		return ;
	a = all->stack_b->index;
	b = all->stack_b->next->index;
	c = all->stack_b->next->next->index;
	if (b > c && b > a)
		rrb(all, 1);
	else if (a > b && a > c)
		rb(all, 1);
	a = all->stack_b->index;
	b = all->stack_b->next->index;
	if (a > b)
		sb(all, 1);
}