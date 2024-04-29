/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:18:19 by loigonza          #+#    #+#             */
/*   Updated: 2024/04/29 17:11:32 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
void	printstack(t_list *stack)
{
	t_list *tmp;

	tmp = stack;
	while (tmp)
	{
	//	printf("%d\n", tmp -> content);
		tmp = tmp -> next;
	}
}
*/
void	free_stack(t_list **stack)
{
	t_list *tmp;
	t_list *next;

	if (*stack && stack)
	{
		tmp = *stack;
		while (tmp)
		{
			next = tmp -> next;
			free(tmp);
			tmp = next;
		}
		*stack = NULL;
	}
}

void	move_min_on_top(t_list **stack, int five)
{
	t_list *min_node;

	min_node = get_min(*stack);
	while (*stack != min_node)
	{
		if (five)
		{
			if (!min_node -> above_median)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (min_node -> above_median)
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
			if (node_tmp -> above_median)
			{
				if (bolean)
					ra(stack);//aqui rotamos stack_a;
				else
					rb(stack);//aqui rotamos stack_b;
			}
			else
			{
				if (bolean)
					rra(stack);//aqui rev_rotate de stack_a;
				else
					rrb(stack);//aqui rev_rotate de stack_b;
			}	
		}
}

t_list	*get_node_min_cost(t_list *stack)
{
	int max;
	t_list	*tmp;

	if (!stack)
		return (NULL);
	max = INT_MAX;
	while (stack)
	{
		if (stack -> cost < max)
		{
			max = stack -> cost;
			tmp = stack;
		}
		else
			stack= stack -> next;
	}
	return (tmp);
}
static void	stack_a_to_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_tmp;

	node_tmp = get_node_min_cost(*stack_a);
	//printf("%d\n", node_tmp -> content);
	//mirar si los dos estan encima de la mediana o no.
	if (node_tmp -> above_median == node_tmp -> target -> above_median)
	{
		if (node_tmp -> above_median)
			while (*stack_a != node_tmp && *stack_b != node_tmp -> target)
				rr(stack_a, stack_b);
		else
			while (*stack_a != node_tmp && *stack_b != node_tmp -> target)
				rrr(stack_a, stack_b);
	}
	get_min_on_top(stack_a, node_tmp, 1);
	get_min_on_top(stack_b, node_tmp -> target, 0);
	pb(stack_a, stack_b);
}

static void	stack_b_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	get_min_on_top(stack_a, (*stack_b) -> target, 1);
	pa(stack_b, stack_a);
}


void	sum_cost(t_list *stack)
{
	while (stack)
	{
		if (stack -> above_median == stack -> target -> above_median
				&& stack -> cost < stack -> target -> cost)
			stack -> cost = stack -> target -> cost;
		else if (stack -> above_median != stack -> target -> above_median)
		   stack -> cost = stack -> cost + stack -> target -> cost;
	stack = stack -> next;
	}
}


void	setting_cost(t_list *stack)
{
	int	len;
	t_list *node_tmp;

	len = ft_lstsize(stack);
	while (stack)
	{
		if (stack -> above_median)
			stack -> cost = stack -> index;
		else
		{
 		 node_tmp = get_node_min_cost(stack);
		 stack -> cost = len - (stack -> index);
		}
		stack = stack -> next;
	}
}

void	set_cost(t_list *stack_a, t_list *stack_b)
{
	setting_cost(stack_a);
	setting_cost(stack_b);
	sum_cost(stack_a);
}

void	min_target(t_list *stack_a, t_list *stack_b)
{
	int	min;
	t_list *tmp;

	while (stack_a)
	{
		min = INT_MIN;
		tmp = stack_b;
		stack_a -> target = get_max(stack_b);
		while (tmp)
		{
			if (stack_a -> content > tmp -> content && tmp -> content >= min)
			{
				stack_a -> target = tmp;
				min = tmp -> content;
			}
			tmp = tmp -> next;
		}
		stack_a = stack_a -> next;
	}
}

void	max_target(t_list *stack_b, t_list *stack_a)
{
	int max;
	t_list *tmp;

	while (stack_b)
	{
		max = INT_MAX;
		tmp = stack_a;
		stack_b -> target = get_min(stack_a);
		while (tmp)
		{
			if (stack_b -> content < tmp -> content && tmp -> content <= max)
			{
				max = tmp -> content;
				stack_b -> target = tmp;
			}
			tmp = tmp -> next;
		}
		stack_b = stack_b -> next;
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
			stack -> index = i;
			stack -> above_median = 1;
		}
		else
		{
			stack -> index = i;
			stack -> above_median = 0;
		}
		i++;
		stack = stack -> next;
	}
}

void	order_all(t_list **stack_a, t_list **stack_b, int five)
{
	int	lst_size_a;
	int	i;

	i = 0;
	lst_size_a = ft_lstsize(*stack_a);
	//printf("l %d\n", lst_size_a);
	while (i < 2 && lst_size_a > 3 && !lst_sorted(*stack_a))
	{
		pb(stack_a, stack_b);
		lst_size_a--;
		i++;
	}
	while (lst_size_a > 3 && !lst_sorted(*stack_a))
	{
		ft_put_index(*stack_a);
		ft_put_index(*stack_b);
		min_target(*stack_a, *stack_b);
		//printf("size, %d\n", ft_lstsize(*stack_a));
		set_cost(*stack_a, *stack_b);
		//printf("size, %d\n", ft_lstsize(*stack_a));
		stack_a_to_stack_b(stack_a, stack_b);
		//printf("size, %d\n", ft_lstsize(*stack_a));
		lst_size_a--;
	}
	//printf("size, %d\n", ft_lstsize(*stack_a));
	//printf("==============");
	//printstack(*stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_put_index(*stack_a);
		ft_put_index(*stack_b);
		max_target(*stack_b, *stack_a);
		//printf("%d\n", ft_lstsize(*stack_a
		stack_b_to_stack_a(stack_a, stack_b);
	}
	move_min_on_top(stack_a, five);
}
