/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:10:22 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/08 16:40:21 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*rra : reverse rotate a - сдвигает вниз все элементы стека a на 1.
			Последний элемент становится первым.
rrb : reverse rotate b - сдвинуть вниз все элементы стека b на 1.
			Последний элемент становится первым.
rrr : rra и rrb одновременно.*/

#include "push_swap.h"

void	rra(t_all *all, int flag)
{
	if (all->size_a > 1)
		all->stack_a = all->stack_a->prev;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_all *all, int flag)
{
	if (all->size_b > 1)
		all->stack_b = all->stack_b->prev;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_all *all, int flag)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		rra(all, 0);
		rrb(all, 0);
		if (flag)
			write (1, "rrr\n", 4);
	}
}