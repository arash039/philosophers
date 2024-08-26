/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:58:39 by ashojach          #+#    #+#             */
/*   Updated: 2023/08/18 12:12:38 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philo *philo)
{
	printf("%d [1] died! \n", philo->data->t_die);
	destroy(philo);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	if (ft_check_args(ac, av))
		data = malloc(sizeof(t_data));
	else
		return (0);
	philo = malloc(sizeof(t_philo) * (ft_atoi(av[1]) + 1));
	if (!data || !philo)
		return (printf("malloc error!\n"), destroy(philo), 0);
	data_init(ac, av, data);
	philo_init(philo, data);
	if (data->n_philo > 1)
	{
		thread_init(philo);
		destroy(philo);
	}
	else
		one_philo(philo);
	return (0);
}
