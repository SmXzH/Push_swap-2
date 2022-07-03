/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:31:12 by szhakypo          #+#    #+#             */
/*   Updated: 2022/07/03 20:57:13 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct node
{
	int			num;
	int			index;
	int			flag;
	struct node	*next;
}t_node;

typedef struct all
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;
	int		min;
	int		max;
	int		med;
}t_all;

t_all	*parse(char	**av);
char	**ft_first_parse(char **av);
void	same_num(char	**str);
void	check_arg(char **arr);
void	free_arr(char **arr, int flag);
void	error(void);
t_all	*init_struct(char **str);
t_node	*new_list(int num, int index);
void	listadd(t_node **stack_a, t_node *new);
void	add_to_stack(t_all *all, char **arr);
void	bubble_sort(t_all *all, int *sort, int *non_sort, int len);
void	create_stack(t_all	*all, int *sort, int *non_sort, int len);
void	med_min_max(t_all *all);
void	sorting(t_all *all);
int		sort_true(t_all *all);
void	free_stack(t_all *all);

//Instructions
void	sa(t_all *all, int flag);
void	sb(t_all *all, int flag);
void	ss(t_all *all);
void	push_a(t_all *all);
void	push_b(t_all *all);
void	pb(t_all *all, int flag);
void	pa(t_all *all, int flag);
void	ra(t_all *all, int flag);
void	rb(t_all *all, int flag);
void	rr(t_all *all, int flag);
void	rra(t_all *all, int flag);
void	rrb(t_all *all, int flag);
void	rrr(t_all *all, int flag);

//sorting
void	sort_tree(t_all *all);
void	sort_five(t_all *all);

#endif