/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:01:40 by loigonza          #+#    #+#             */
/*   Updated: 2024/04/29 13:57:25 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rotate(t_list **stack_a)
{
	  t_list *tmp;
	  t_list *last_pos;

	  last_pos = ft_lstlast(*stack_a);
	  tmp = *stack_a;
	  *stack_a = (*stack_a) -> next;
	  (*stack_a) -> prev = NULL;
	  tmp -> prev = last_pos;
	  last_pos -> next = tmp;
	  tmp -> next = NULL;
}

void	ra(t_list **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
