/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@student.42carcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:29:21 by loigonza          #+#    #+#             */
/*   Updated: 2024/03/26 17:37:51 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <push_swap.h>
#include <unistd.h>

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

	
int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		if (*argv[1])
		{
			if (repeatarg(argv) || sytxfail(argv))
			{
				write (1, "Error\n", 6);
				return (0);
			}
		}
		return (0);
	}
}
