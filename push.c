/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:00:39 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/02 11:09:44 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//modificar push_b para que me sirva para push_a y b;
void	push(t_list **stack_src, t_list **stack_dst)
{
	t_list	*tmp;

	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	if (!*stack_dst)
	{
		*stack_dst = tmp;
		(*stack_dst)->next = NULL;
	}
	else
	{
		(*stack_dst)->prev = tmp;
		tmp -> next = *stack_dst;
		*stack_dst = tmp;
	}
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	if (!stack_b)
		return ;
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
