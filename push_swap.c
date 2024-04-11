/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42carcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:29:21 by loigonza          #+#    #+#             */
/*   Updated: 2024/04/11 18:09:33 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

long	ft_atol(char *argv[])
{
	int		i;
	int		j;
	int		sign;
	long	num;
	
	i = 1;
	j = 0;
	sign = 1;
	num = 0;
	if (argv[i][j] == '-')
	{
		sign = sign * -1;
		j++;
	}
	while (argv[i][j] != '\0')
	{
		num = num * 10 + (argv[i][j] - 48);
		j++;
	}
	num = num * sign;
	return (num);
}

int	repeatarg(char *argv[])
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[i + j])
		{
			k = 0;
			while (argv[i] && argv[i + j] && argv[i][k] == argv[i + j][k])
			{
				k++;
				if (!argv[i][k] && !argv[i + j][k])
					return (1);
			}
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
		while(argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{	
				if (!argv[i][j + 1] || (argv[i][j + 1] < '0' || argv[i][j + 1] > '9'))
					return (1);
				j++;
			}
			else if (argv[i][j] < '0' || argv[i][j] > '9')
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
		if (ft_atol(argv) > INT_MAX || ft_atol(argv) < INT_MIN)
			return (1);
		else
			argv++;
	}
	return (0);
}
	
int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t _list	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (*argv[i])
		{
			if (repeatarg(argv) || sytxfail(argv) || rangeint(argv))
			{
				write (2, "Error\n", 6);
				return (0);
			}
			while (*argv[i])
			{
				//ft_crear_nodo
				//meter contenido de *argv[] pasado por Atoi
				fill_stack(stack_a, argv);//anhadir con esta funcion.
				i++;
			}
		}
		return (0);
	}
}
