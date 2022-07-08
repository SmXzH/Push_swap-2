/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:31:09 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/08 21:36:38 by szhakypo         ###   ########.fr       */
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
	if (sort_true(all))
		free_stack(all);
	if (all->size_a < 6)
	{
		sort_five(all);
		free_stack(all);
	}
	else if (all->size_a > 5)
	{
		call_chunks(all);
		push_back(all);
	}
}

int	main(int ac, char **av)
{
	t_all	*all;

	if (ac > 1)
	{
		all = parse(av);
		sorting(all);
	}
	return (0);
}
