/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:14:45 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/14 12:25:37 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

void	two_args(t_stack *a)
{
	if (a->elem[0].nb > a->elem[1].nb)
		do_rotate(a);
	else
		return ;
}

void	three_args(t_stack *a)
{
	if (a->elem[0].nb > a->elem[1].nb && a->elem[1].nb < a->elem[2].nb)
	{
		if (a->elem[0].nb < a->elem[2].nb)
			do_swap(a);
		else
			do_rotate(a);
	}
	else if (a->elem[0].nb > a->elem[1].nb && a->elem[1].nb > a->elem[2].nb)
	{
		do_swap(a);
		do_reverse_rotate(a);
	}
	else if (a->elem[0].nb < a->elem[1].nb && a->elem[1].nb > a->elem[2].nb)
	{
		if (a->elem[0].nb < a->elem[2].nb)
		{
			do_swap(a);
			do_rotate(a);
		}
		else
			do_reverse_rotate(a);
	}
}

static void	put_min_on_top(t_stack *stack)
{
	int	opt;

	if (stack->elem[id_min(stack)].rot_min[0]
		< stack->elem[id_min(stack)].rot_min[1])
	{
		opt = stack->elem[id_min(stack)].rot_min[0];
		while (opt--)
			do_rotate(stack);
	}
	else
	{
		opt = stack->elem[id_min(stack)].rot_min[1];
		while (opt--)
			do_reverse_rotate(stack);
	}
}

static void	find_best(t_stack *src, t_stack *dst)
{
	int	i;
	int	opt;
	int	id;

	i = 0;
	opt = src->elem[0].best_nb;
	id = 0;
	while (i < src->len)
	{
		if (src->elem[i].best_nb < opt)
		{
			opt = src->elem[i].best_nb;
			id = i;
		}
		i++;
	}
	return (exec_best(src, dst, id));
}

void	do_algo(t_stack *a, t_stack *b)
{
	int	len;

	if (!is_sort(a, a->len))
		return ;
	len = a->len;
	do_push(a, b);
	do_push(a, b);
	new_rot_min(a, b);
	while (a->len > 2)
	{
		find_best(a, b);
		do_push(a, b);
		new_rot_min(a, b);
	}
	while (a->len < len)
	{
		find_best(b, a);
		do_push(b, a);
		new_rot_min(a, b);
	}
	put_min_on_top(a);
}
