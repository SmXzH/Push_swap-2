/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:10:22 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/30 11:37:41 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*rra : reverse rotate a - сдвигает вниз все элементы стека a на 1.
			Последний элемент становится первым.
rrb : reverse rotate b - сдвинуть вниз все элементы стека b на 1.
			Последний элемент становится первым.
rrr : rra и rrb одновременно.*/

#include "push_swap.h"

//t_node	*find_pre_last(t_all *all)
//{
//	t_node *tmp;
//	t_node *node;

//	if (!all)
//		return (NULL);
//	node = all->stack_a;
//	while (node->next != NULL)
//	{
//		tmp = node;
//		node = node->next;
//	}
//	return (tmp);
//}

void	rra(t_all *all, int flag)
{
	t_node	*tmp;
	t_node	*pre_last;
	
	tmp = all->stack_a;
	while (tmp->next != NULL)
	{
		pre_last = tmp;	
		tmp = tmp->next;
	}
	if (all->size_a > 1)
	{
		tmp->next = all->stack_a;
		pre_last->next = NULL;
		all->stack_a = tmp;
	}
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_all *all, int flag)
{
	t_node	*tmp;
	t_node	*pre_last;
	
	tmp = all->stack_b;
	while (tmp->next != NULL)
	{
		pre_last = tmp;
		tmp = tmp->next;
	}
	if (all->size_b > 1)
	{
		tmp->next = all->stack_b;
		pre_last->next = NULL;
		all->stack_a = tmp;
	}
	if (flag)
		write(1, "rra\n", 4);
}

void	rrr(t_all *all, int flag)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		rra(all, 0);
		rrb(all, 0);
		if(flag)
			write(1, "rrr\n", 4);
	}
}