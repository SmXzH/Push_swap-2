/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:21:31 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/03 18:38:56 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*init_struct(char **str)
{
	t_all 	*all;
	int		i;
	
	i = 0;
	while (str[i])
		i++;
	all = malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->size_a = i;
	all->size_b = 0;
	all->min = 1;
	all->max = 0;
	all->med = 0;
	return (all);
}

t_node	*new_list(int num, int index)
{
	t_node	*lst;

	lst = malloc(sizeof(t_node));
	if (!lst)
		return (NULL);
	lst->num = num;
	lst->flag = 0;
	lst->index = index;
	lst->next = NULL;
	return (lst);
}

void	listadd(t_node **stack_a, t_node *new)
{
	t_node	*tmp;
	
	if (!new)
		return ;
	tmp = *stack_a;
	if (tmp)
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*stack_a = new;
}