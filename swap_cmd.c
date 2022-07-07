/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:39:25 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/04 18:59:00 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*sa : swap a — поменять местами первые 2 элемента в верхней части стека a.
			Ничего не делать, если есть только один элемент или его нет).
sb : swap b — поменять местами первые 2 элемента в верхней части стека b.
			Ничего не делать, если есть только один элемент или его нет).
ss : sa и sb одновременно.*/

#include "push_swap.h"

void	sa(t_all *all, int flag)
{
	int	tmp;
	
	if (all->size_a < 2)
		return ;
	tmp = all->stack_a->index;
	all->stack_a->index = all->stack_a->next->index;
	all->stack_a->next->index = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_all *all, int flag)
{
	int	tmp;
	
	if (all->size_b < 2)
		return ;
	tmp = all->stack_b->index;
	all->stack_b->index = all->stack_b->next->index;
	all->stack_b->next->index = tmp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_all *all)
{
	if (all->size_a > 1 && all->size_b > 1)
		sa(all, 0);
		sb(all, 0);
		write(1,"ss\n", 3);
}