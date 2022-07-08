/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunki.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:57:37 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/08 21:35:45 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_block(t_all *all)
{
	if (all->size_a > 400)
		return (55);
	else if (all->size_a > 600)
		return (80);
	else if (all->size_a > 100)
		return (35);
	else if (all->size_a > 50)
		return (24);
	else
		return (4);
}

void	call_chunks(t_all *all)
{
	int	block;

	block = find_block(all);
	while (all->size_a > block)
	{
		chunk(all);
		block *= 2;
	}
}

void	chunk(t_all *all)
{
	int	i;
	int	chunk;
	int	size;

	chunk = find_block(all);
	size = all->size_a / chunk;
	i = 0;
	while (all->size_a > 0)
	{
		if (all->stack_a->index >= i * chunk
			&& all->stack_a->index <= ((i + 1) * chunk))
		{
			pb(all, 1);
			if (all->stack_b->index < ((i * chunk) + ((i + 1) * chunk)) / 2)
				rb(all, 1);
		}
		else
			ra(all, 1);
		if (all->size_b == ((i + 1) * chunk))
			i++;
	}
}

void	printstack(t_node *top)
{
	int	tmp;

	tmp = top->index;
	printf("index : %d\n", top->index);
	top = top->next;
	while (tmp != top->index)
	{
		printf("index : %d\n", top->index);
		top = top->next;
	}
}

void	med_min_max_b(t_all *all)
{
	int		i;
	int		min;
	int		max;
	t_node	*tmp;

	tmp = all->stack_b;
	if (all->size_b == 0)
		return ;
	i = all->size_b;
	max = all->stack_b->index;
	while (i-- > 0)
	{
		if (min > all->stack_b->index)
			min = all->stack_b->index;
		if (max < all->stack_b->index)
			max = all->stack_b->index;
		all->stack_b = all->stack_b->next;
	}
	all->min_b = min;
	all->max_b = max;
	all->med_b = (min + max) / 2;
	all->stack_b = tmp;
}
