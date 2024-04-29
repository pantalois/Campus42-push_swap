/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42carcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:42:14 by loigonza          #+#    #+#             */
/*   Updated: 2024/04/29 17:31:50 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				above_median;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int	main(int argc, char *argv[]);

//control errors
int	rangeint(char *argv[]);
int	sytxfail(char *argv[]);
int	repeatarg(char *argv[]);

//==================//
long	ft_atol(char *argv);

//stacks
void	fill_stack(t_list **stack_a, int nodo);
t_list	*ft_lstlast(t_list *lst);
int		lst_sorted(t_list *stack_a);

//Commands
//push
void	push(t_list **stack_src, t_list **stack_dst);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
//swap
void	swap(t_list **stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
//rotate
void	rotate(t_list **stack_a);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
//rev_rotate
void	rev_rotate(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

//Sort
void		ft_sort_three(t_list **stack_a);
void		ft_sort_four(t_list **stack_a, t_list **stack_b);
void		ft_sort_five(t_list **stack_a, t_list **stack_b);
int			ft_lstsize(t_list *lst);
//void		ft_median(t_list **stack_a);
void		order_all(t_list **stack_a, t_list **stack_b, int five);
void		ft_put_index(t_list *stack);
void		set_cost(t_list *stack_a, t_list *stack_b);
void		setting_cost(t_list *stack);
t_list		*get_node_min_cost(t_list *stack);
void		get_min_on_top(t_list **stack, t_list *node_tmp, int bol);
void		free_stack(t_list **stack);

//
t_list	*get_max(t_list *stack_a);
t_list	*get_min(t_list *stack_a);

#endif
