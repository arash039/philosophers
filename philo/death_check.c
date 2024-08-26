/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:55:11 by ashojach          #+#    #+#             */
/*   Updated: 2023/08/17 20:55:46 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	die_cal(t_philo *philo, long long die_t, long long t_now)
{
	int			i;

	i = 0;
	while (i < philo->data->n_philo)
	{
		if (t_now - philo[i].last_meal > die_t)
		{
			pthread_mutex_lock(&philo->data->print);
			pthread_mutex_lock(&philo->data->m_dead);
			printf("%llu [%d] died! \n",
				delta_time(philo->data->time_start), philo[i].id);
			philo->data->dead = 1;
			pthread_mutex_unlock(&philo->data->m_dead);
			pthread_mutex_unlock(&philo->data->print);
			pthread_mutex_unlock(&philo->data->lastmeal);
			return (1);
		}
		i++;
	}
	return (0);
}

int	philo_is_dead(t_philo *philo)
{
	long long	dead_time;
	long long	time_now;
	int			result;

	dead_time = (long long)philo->data->t_die;
	pthread_mutex_lock(&philo->data->timewarp);
	time_now = timer();
	pthread_mutex_unlock(&philo->data->timewarp);
	pthread_mutex_lock(&philo->data->lastmeal);
	result = die_cal(philo, dead_time, time_now);
	if (result == 0)
		pthread_mutex_unlock(&philo->data->lastmeal);
	return (result);
}

int	check_death(t_data *data)
{
	pthread_mutex_lock(&data->m_dead);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->m_dead);
		return (1);
	}
	pthread_mutex_unlock(&data->m_dead);
	return (0);
}
