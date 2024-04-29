/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:02:11 by loigonza          #+#    #+#             */
/*   Updated: 2024/04/29 13:55:51 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_list **stack_a, int nodo)
{
	t_list *new_node;
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
		
		


