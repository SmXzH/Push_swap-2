/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:22:57 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/03 19:38:14 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*pa : push a — взять первый элемент в верхней части b и поместить его в
				верхнюю часть a. Ничего не делать, если b пусто.
pb : push b — взять первый элемент в верхней части a и поместить его в
				верхнюю часть b. Ничего не делать, если a пусто.*/

void	push_a(t_all *all)
{
	t_node	*tmp;

	tmp = all->stack_b->next;
	if (all->stack_a)
	{
		all->stack_b->next = all->stack_a;
		all->stack_a = all->stack_b;
	}
	else
	{
		all->stack_a = all->stack_b;
		all->stack_a->next = NULL;
	}
	all->stack_b = tmp;
}

void	push_b(t_all *all)
{
	t_node	*tmp;
	
	tmp = all->stack_a->next;
	if (all->stack_b)
	{
		all->stack_a->next = all->stack_b;
		all->stack_b = all->stack_a;
	}
	else
	{
		all->stack_b = all->stack_a;
		all->stack_b->next = NULL;
	}
	all->stack_a = tmp;
}

void	pb(t_all *all, int flag)
{
	if (all->size_a == 0)
		return ;
	push_b(all);
	if (all->size_a == 1)
		all->stack_a = NULL;
	all->size_a--;
	all->size_b++;
	if (flag)
		write(1,"pb\n",3);
}

void	pa(t_all *all, int flag)
{
	if (all->size_b == 0)
		return ;
	push_a(all);
	if (all->size_b == 1)
		all->stack_b = NULL;
	all->size_a++;
	all->size_b--;
	if (flag)
		write(1,"pa\n",3);	
}