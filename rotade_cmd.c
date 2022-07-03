/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotade_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:05:14 by szhakypo          #+#    #+#             */
/*   Updated: 2022/06/30 11:37:00 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ra : rotate a - сдвигает вверх все элементы стека a на 1.
			Первый элемент становится последним.
rb : rotate b - сдвинуть вверх все элементы стека b на 1.
			Первый элемент становится последним.
rr : ra и rb одновременно.*/

#include "push_swap.h"

void	ra(t_all *all, int flag)
{
	t_node	*tmp;
	
	tmp = all->stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (all->size_a > 1)
	{
		tmp->next = all->stack_a;
		all->stack_a = all->stack_a->next;
		tmp->next->next = NULL;
		if (flag)
			write (1, "ra\n", 3);
	}
}

void	rb(t_all *all, int flag)
{
	t_node	*tmp;
	
	tmp = all->stack_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (all->size_b > 1)
	{
		tmp->next = all->stack_b;
		all->stack_b = all->stack_b->next;;
		tmp->next->next = NULL;
		if (flag)
			write (1, "ra\n", 3);
	}
}

void	rr(t_all *all, int flag)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		ra(all, 0);
		rb(all, 0);
		if (flag)
			write(1,"rr\n", 3);
	}
}