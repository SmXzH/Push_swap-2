/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:06:28 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/07 21:17:58 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_all *all)
{
	int	i;

	i = all->size_b;
	med_min_max_b(all);
	while (i != 0)
	{
		if (all->stack_b->index == all->max_b)
			pa(all, 1);
		else
			rb(all, 1);
		i--;
	}
	
}