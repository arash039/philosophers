/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:51:09 by ashojach          #+#    #+#             */
/*   Updated: 2023/08/17 21:00:51 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timer(void)
{
	struct timeval	tp;
	long long		ms;

	gettimeofday(&tp, NULL);
	ms = (tp.tv_sec * 1000) + (tp.tv_usec * 0.001);
	return (ms);
}

long long	delta_time(long long time)
{
	if (time > 0)
		return (timer() - time);
	return (0);
}

void	destroy(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->n_philo)
	{
		pthread_mutex_destroy(&philo->data->fks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->data->timewarp);
	pthread_mutex_destroy(&philo->data->meal_count);
	pthread_mutex_destroy(&philo->data->print);
	pthread_mutex_destroy(&philo->data->m_dead);
	pthread_mutex_destroy(&philo->data->lastmeal);
	pthread_mutex_destroy(&philo->data->m_end);
	free(philo->data->fks);
	free(philo->data);
	free(philo);
}

void	printer(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	if (check_death(philo->data) == 1 || philo->data->end == 1)
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	printf("%llu [%d] %s\n",
		delta_time(philo->data->time_start), philo->id, str);
	usleep(5);
	pthread_mutex_unlock(&philo->data->print);
}
