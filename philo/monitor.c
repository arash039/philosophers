/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:56:08 by ashojach          #+#    #+#             */
/*   Updated: 2023/08/18 12:26:31 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	//usleep(5000);
	if (philo->data->n_must_eat > 0)
	{
		while (!philo->data->end && !check_death(philo->data))
		{
			if (philo_is_dead(philo) || philo->data->end)
				break ;
			if (finish_check(philo))
				break ;
		}
	}
	else
	{
		while (check_death(philo->data) == 0)
		{
			if (philo_is_dead(philo))
				break ;
		}
	}
	return (NULL);
}
