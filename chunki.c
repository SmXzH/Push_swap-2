/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunki.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:57:37 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/07 21:08:06 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_block(t_all *all)
{
	if (all->size_a > 100)
		return (15);
	if (all->size_a > 50)
		return (8);
	if (all->size_a > 400)
		return (38);
	else
		return (4);
}

void	call_chunks(t_all *all)
{
	int	block;
	int	i;

	i = 1;
	block = find_block(all);
	
	while (all->size_a > block)
	{
		chunk(all, i, block);
		i = block + 1;
		block *= 2;
	}
}

void	chunk(t_all *all, int min, int max)
{
	int	i;
	int	chunk = find_block(all);
	
	min = 0;
	max = 0;
	i = 0;
	printf ("size of A : %d\n", all->size_a);
	while (all->size_a > 1)
	{
		if (all->stack_a->index >= i * chunk && all->stack_a->index <= ((i + 1) * chunk))
			pb(all, 1);
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
	int	i;
	int	min;
	int	max;
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

//void	sort_a(t_all *all)
//{
	
//}