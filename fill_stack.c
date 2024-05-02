/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:02:11 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/02 16:25:40 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_list **stack_a, int nodo)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node -> content = nodo;
	new_node -> next = NULL;
	if (!*stack_a)
	{
		*stack_a = new_node;
		new_node -> prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack_a);
		last_node -> next = new_node;
		new_node -> prev = last_node;
	}
}

void	ft_sort_three(t_list **stack_a)
{
	t_list	*max_node;

	max_node = get_max(*stack_a);
	if (((*stack_a)->content) == (max_node->content))
		ra(stack_a);
	else if (((*stack_a)->next->content) == (max_node->content))
		rra(stack_a);
	if (((*stack_a)->content) > ((*stack_a)->next->content))
		sa(stack_a);
}

void	ft_create_stack(t_list **stack_a, char *argv[])
{
	int	nodo;
	int	i;

	i = 1;
	while (argv[i])
	{
		nodo = (int)ft_atol(argv[i]);
		fill_stack(stack_a, nodo);
		i++;
	}
}

int	ft_print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*next;

	if (*stack && stack)
	{
		tmp = *stack;
		while (tmp)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
		*stack = NULL;
	}
}
