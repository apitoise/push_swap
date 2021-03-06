/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:46:24 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/09 16:46:24 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define ROTATE_A 0
# define R_ROTATE_A 1
# define ROTATE_B 2
# define R_ROTATE_B 3

typedef enum e_best
{
	MIN,
	RR,
	RRR,
}			t_best;

typedef struct s_elem
{
	int	nb;
	int	rot_min[4];
	int	best;
	int	best_nb;	
}				t_elem;

typedef struct s_stack
{
	t_elem	*elem;
	int		len;
	char	name;
}				t_stack;

int			check_arg(int arg_nb, char **args, t_stack *a);
void		do_algo(t_stack *a, t_stack *b);
void		two_args(t_stack *a);
void		three_args(t_stack *a);
void		exec_best(t_stack *a, t_stack *b, int id);
void		min_bis(int *rot_min, t_stack *src, t_stack *dst);
void		rr_bis(int *rot_min, t_stack *src, t_stack *dst);
void		rrr_bis(int *rot_min, t_stack *src, t_stack *dst);

void		calculate_best(t_stack *a);
void		new_rot_min(t_stack *a, t_stack *b);
int			clean_exit(t_stack *a, t_stack *b);
long long	ft_atoi_check(const char *str);
int			ft_error(void);
int			is_sort(t_stack *a, int len);
int			id_max(t_stack *stack);
int			id_min(t_stack *stack);
int			closer_max(t_stack *stack, int nb);
int			closer_min(t_stack *stack, int nb);

void		do_push(t_stack *src, t_stack *dst);
void		do_rotate(t_stack *stack);
void		double_rotate(t_stack *a, t_stack *b);
void		do_reverse_rotate(t_stack *stack);
void		double_reverse_rotate(t_stack *a, t_stack *b);
void		do_swap(t_stack *stack);

#endif
