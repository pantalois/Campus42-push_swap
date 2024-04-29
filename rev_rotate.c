/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:43:02 by loigonza          #+#    #+#             */
/*   Updated: 2024/04/29 13:57:38 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack) -> prev = NULL;
	(*stack) -> next = tmp;
	tmp -> prev = *stack;
	while (tmp -> next != *stack)
		tmp = tmp -> next;
	tmp -> next = NULL;
}

void	rra(t_list **stack)
{
	rev_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	rev_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
