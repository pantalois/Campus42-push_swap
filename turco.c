/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turco.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:19:34 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/02 16:41:32 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_target(t_list *stack_a, t_list *stack_b)
{
	int		min;
	t_list	*tmp;

	while (stack_a)
	{
		min = INT_MIN;
		tmp = stack_b;
		stack_a->target = get_max(stack_b);
		while (tmp)
		{
			if (stack_a->content > tmp->content && tmp->content >= min)
			{
				stack_a->target = tmp;
				min = tmp->content;
			}
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
}

void	max_target(t_list *stack_b, t_list *stack_a)
{
	int		max;
	t_list	*tmp;

	while (stack_b)
	{
		max = INT_MAX;
		tmp = stack_a;
		stack_b->target = get_min(stack_a);
		while (tmp)
		{
			if (stack_b->content < tmp->content && tmp->content <= max)
			{
				max = tmp->content;
				stack_b->target = tmp;
			}
			tmp = tmp->next;
		}
		stack_b = stack_b->next;
	}
}

void	ft_put_index(t_list *stack)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(stack);
	if (len % 2 == 0)
		len /= 2;
	else if (len % 2 != 0)
		len = (len + 1) / 2;
	while (stack)
	{
		if (i < len)
		{
			stack->index = i;
			stack->above_median = 1;
		}
		else
		{
			stack->index = i;
			stack->above_median = 0;
		}
		i++;
		stack = stack->next;
	}
}

void	order_all(t_list **stack_a, t_list **stack_b, int five)
{
	int	lst_size_a;
	int	i;

	i = 0;
	lst_size_a = ft_lstsize(*stack_a);
	while (i++ < 2 && lst_size_a-- > 3 && !lst_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (lst_size_a-- > 3 && !lst_sorted(*stack_a))
	{
		ft_put_index(*stack_a);
		ft_put_index(*stack_b);
		min_target(*stack_a, *stack_b);
		set_cost(*stack_a, *stack_b);
		stack_a_to_stack_b(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_put_index(*stack_a);
		ft_put_index(*stack_b);
		max_target(*stack_b, *stack_a);
		stack_b_to_stack_a(stack_a, stack_b);
	}
	move_min_on_top(stack_a, five);
}
