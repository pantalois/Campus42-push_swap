/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42carcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:29:21 by loigonza          #+#    #+#             */
/*   Updated: 2024/05/15 15:17:20 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

long	ft_atol(char *argv)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32)
		i++;
	if (argv[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (argv[i] == '+')
		i++;
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		num = num * 10 + (argv[i] - 48);
		i++;
	}
	num = num * sign;
	return (num);
}

int	repeatarg(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[i + j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[i + j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	sytxfail(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (!argv[i][j])
			return (1);
		if (argv[i][j] == '-' || argv[i][j] == '+')
		{
			if (!(argv[i][j + 1] >= '1' && argv[i][j + 1] <= '9'))
				return (1);
			j++;
		}
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	rangeint(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (1);
		else
			i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (repeatarg(argv) || sytxfail(argv) || rangeint(argv))
			return (ft_print_error());
		ft_create_stack(&stack_a, argv);
		if (!lst_sorted(stack_a))
		{
			if (ft_lstsize(stack_a) == 2)
				sa(&stack_a);
			else if (ft_lstsize(stack_a) == 3)
				ft_sort_three(&stack_a);
			else if (ft_lstsize(stack_a) <= 5)
				order_all(&stack_a, &stack_b, 1);
			else
				order_all(&stack_a, &stack_b, 0);
		}
		free_stack(&stack_a);
	}
	return (0);
}
