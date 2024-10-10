/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:35:27 by joafern2          #+#    #+#             */
/*   Updated: 2024/10/09 20:55:29 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft.h"

typedef struct s_record_moves
{
	int	target_b_index;
	int	ra_moves;
	int	rb_moves;
	int	rra_moves;
	int	rrb_moves;
	int	rr_moves;
	int	rrr_moves;
	int	ra_rrb_moves;
	int	rb_rra_moves;
	int	total_moves;
}	t_record_moves;

typedef structc s_cheapest_moves
{
	int	cheapest_ra;
	int	cheapest_rra;
	int	cheapest_rb;
	int	cheapest_rrb;
	int	cheapest_rr;
	int	cheapest_rrr;
	int	cheapest_ra_rrb;
	int	cheapest_rb_rra;
	int	cheapest_move_count;
	int	cheapest_a_index;
}	t_cheapest_moves;

void	swap_a(int *a);
void	push_a(int *a, int *b, int *a_size, int *b_size);
void	push_b(int *a, int *b, int *a_size, int *b_size);
void	rotate_a(int *a, int *a_size);
void	rotate_b(int *b, int *b_size);
void	rotate_rr(int *a, int *b, int *a_size, int *b_size);
void	r_rotate_a(int *a, int *a_size);
void	r_rotate_b(int *b, int *b_size);
void	r_rotate_rr(int *a, int *b, int *a_size, int *b_size);
int		is_duplicate(int nbr, int *a, int i);
int		ft_isdecimal(char *c);
int		ft_atoi(const char *nptr, int *error);
int		parser(int *a, int *b, int a_size, char **argv);
void	write_stacks(int *a, int *b, int a_size, int b_size);
int		allocate_stacks(int **a, int **b, int a_size);
void	greedy_insertion(int *a, int *b, int *a_size, int *b_size);
int		edge_cases(int *a, int a_size);
int		sorted(int *a, int a_size);
void	sort_two(int *a, int a_size);
void	sort_three(int *a, int a_size);
int		find_max_index(int *b, int b_size);
int		find_min_index(int *a, int a_size);
int		find_a_target_position(int *stack, int stack_size, int nbr);
int		find_b_target_position(int *stack, int stack_size, int nbr);
void	calculate_best_moves(int *a, int *b, int a_size, int b_size);
void	calculate_moves(int a_size, int b_size, int a_index, record_moves *moves);
void	execute_best_moves(int *a, int *b, int a_size, int b_size, cheapest_moves *cheapest);
void	execute_rotation(int *a, int *b, int a_size, int b_size, cheapest_moves *cheapest);
void	execute_reverse_rotation(int *a, int *b, int a_size, int b_size,cheapest_moves *cheapest);
void	execute_ra_rrb(int *a, int *b, int a_size, int b_size, cheapest_moves *cheapest);
void	execute_rb_rra(int *a, int *b, int a_size, int b_size, cheapest_moves *cheapest);
int		best_combination(int one, int two, int three, int four);
void	update_cheapest(cheapest_moves *cheapest, record_moves *current_moves, int i);
void	calculate_total_moves(record_moves *moves);
void	prepare_a(int *a, int a_size, int position);
int		max(int moves1, int moves2);
int		min(int moves1, int moves2);

#endif
