/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:53:31 by ashojach          #+#    #+#             */
/*   Updated: 2023/08/17 21:17:22 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	finish_check(t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < philo->data->n_philo && !check_death(philo->data))
	{
		pthread_mutex_lock(&philo->data->meal_count);
		if (philo[i].meal_count == philo->data->n_must_eat)
			j += 1;
		i++;
		pthread_mutex_unlock(&philo->data->meal_count);
	}
	if (j == philo->data->n_philo)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%llu all ate %d times. execution stopped!\n",
			delta_time(philo->data->time_start), philo->data->n_must_eat);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_lock(&philo->data->m_end);
		philo->data->end = 1;
		pthread_mutex_unlock(&philo->data->m_end);
		return (1);
	}
	return (0);
}

int	end_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_end);
	if (philo->data->end == 1)
	{
		pthread_mutex_unlock(&philo->data->m_end);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->m_end);
	return (0);
}
