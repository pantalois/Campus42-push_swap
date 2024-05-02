/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:23:13 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/02 14:07:33 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_pos;

	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	last_pos = lst;
	return (last_pos);
}

int	lst_sorted(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp && tmp->next)
	{
		if ((tmp->content) < (tmp->next->content))
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

t_list	*get_max(t_list *stack_a)
{
	t_list	*max_node;
	int		num;

	num = INT_MIN;
	while (stack_a)
	{
		if ((stack_a->content) > num)
		{
			num = stack_a->content;
			max_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (max_node);
}

t_list	*get_min(t_list	*stack_a)
{
	t_list	*min_node;
	int		num;

	num = INT_MAX;
	while (stack_a)
	{
		if ((stack_a->content) < num)
		{
			num = stack_a->content;
			min_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (min_node);
}

int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	lst_size = 0;
	while (lst != NULL)
	{
		lst_size++;
		lst = lst->next;
	}
	return (lst_size);
}
