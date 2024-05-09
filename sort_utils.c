/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:18:19 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/08 15:45:03 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_to_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_tmp;

	node_tmp = get_node_min_cost(*stack_a);
	if (node_tmp->above_median == node_tmp->target->above_median)
	{
		if (node_tmp->above_median)
			while (*stack_a != node_tmp && *stack_b != node_tmp->target)
				rr(stack_a, stack_b);
		else
			while (*stack_a != node_tmp && *stack_b != node_tmp->target)
				rrr(stack_a, stack_b);
	}
	get_min_on_top(stack_a, node_tmp, 1);
	get_min_on_top(stack_b, node_tmp->target, 0);
	pb(stack_a, stack_b);
}

void	stack_b_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	get_min_on_top(stack_a, (*stack_b)->target, 1);
	pa(stack_b, stack_a);
}

void	sum_cost(t_list *stack)
{
	while (stack)
	{
		if (stack->above_median == stack->target->above_median
			&& stack->cost < stack->target->cost)
			stack->cost = stack->target->cost;
		else if (stack->above_median != stack->target->above_median)
			stack->cost = stack->cost + stack->target->cost;
		stack = stack->next;
	}
}

void	setting_cost(t_list *stack)
{
	int		len;
	t_list	*node_tmp;

	len = ft_lstsize(stack);
	while (stack)
	{
		if (stack->above_median)
			stack->cost = stack->index;
		else
		{
			node_tmp = get_node_min_cost(stack);
			stack->cost = len - (stack->index);
		}
		stack = stack->next;
	}
}

void	set_cost(t_list *stack_a, t_list *stack_b)
{
	setting_cost(stack_a);
	setting_cost(stack_b);
	sum_cost(stack_a);
}
