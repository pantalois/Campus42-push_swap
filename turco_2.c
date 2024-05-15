/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turco_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:22:38 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/15 15:09:07 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_on_top(t_list **stack, int five)
{
	t_list	*min_node;

	min_node = get_min(*stack);
	while (*stack != min_node)
	{
		if (five)
		{
			if (!min_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (min_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
	}
}

void	get_min_on_top(t_list **stack, t_list *node_tmp, int bolean)
{
	while (*stack != node_tmp)
	{
		if (node_tmp->above_median)
		{
			if (bolean)
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (bolean)
				rra(stack);
			else
				rrb(stack);
		}
	}
}

t_list	*get_node_min_cost(t_list *stack)
{
	int		max;
	t_list	*tmp;

	if (!stack)
		return (NULL);
	max = INT_MAX;
	while (stack)
	{
		if (stack->cost < max)
		{
			max = stack->cost;
			tmp = stack;
		}
		else
			stack = stack->next;
	}
	return (tmp);
}
