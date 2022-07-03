/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:31:09 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/03 21:00:03 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*parse(char	**av)
{
	t_all	*list;
	char	**str;

	str = ft_first_parse(av);
	check_arg(str);
	same_num(str);
	list = init_struct(str);
	add_to_stack(list, str);
	free_arr(str, 0);
	return (list);
}

void	sorting(t_all *all)
{
	if(sort_true(all))
		free_stack(all);
	if (all->size_a < 6)
	{
		sort_five(all);
		free_stack(all);
	}
}

void	print_stack(t_node *top)
{
	int i;

	i = 1;
	while(top != NULL)
	{
		printf("stack %d is %d and index = %d\n", i, top->num, top->index);
		top = top->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_all	*all;
	if (ac > 1)
	{
		all = parse(av);
		sorting(all);
		print_stack(all->stack_a);
	}
	return (0);
}

//gcc -Llibft -lft *.c *.h 