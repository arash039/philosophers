/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:46:56 by ashojach          #+#    #+#             */
/*   Updated: 2023/08/17 21:02:18 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *num)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((num[i] >= 9 && num[i] <= 13) || num[i] == 32)
		i++;
	if (num[i] == '-')
		return (-1);
	if (num[i] == '+')
		i++;
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = res * 10 + (num[i] - 48);
		i++;
	}
	return (res);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (ft_print_error(0));
	while (i < ac)
	{
		if (ft_atoi(av[i]) >= 0 && ft_isdigit(av[i]))
			i++;
		else
			return (ft_print_error(1));
		if (ft_atoi(av[1]) == 0)
			return (ft_print_error(2));
		if (av[5])
		{
			if (ft_atoi(av[5]) == 0)
				return (ft_print_error(3));
		}
	}
	return (1);
}

int	ft_print_error(int i)
{
	if (i == 0)
		printf("not enough arguments!\n");
	if (i == 1)
		printf("invalid arguments!\n");
	if (i == 2)
		printf("there should be at least 1 philosopher!\n");
	if (i == 3)
		printf("number of meals can not be 0!\n");
	return (0);
}
