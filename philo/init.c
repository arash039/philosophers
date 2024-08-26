/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:49:22 by ashojach          #+#    #+#             */
/*   Updated: 2023/08/18 12:12:33 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(int ac, char **av, t_data *data)
{
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_must_eat = ft_atoi(av[5]);
	else
		data->n_must_eat = 0;
	data->end = 0;
	return ;
}

void	mutex_init(t_data *data)
{
	pthread_mutex_init(&data->timewarp, NULL);
	pthread_mutex_init(&data->meal_count, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->m_dead, NULL);
	pthread_mutex_init(&data->lastmeal, NULL);
	pthread_mutex_init(&data->m_end, NULL);
	pthread_mutex_lock(&data->m_dead);
	data->dead = 0 ;
	pthread_mutex_unlock(&data->m_dead);
}

void	philo_init(t_philo *philo, t_data *dt)
{
	t_data	*data;
	int		i;

	data = (t_data *)dt;
	i = 0;
	mutex_init(dt);
	data->fks = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * (data->n_philo + 1));
	while (i < data->n_philo)
	{
		philo[i].data = dt;
		philo[i].fk1 = i;
		if (i == data->n_philo - 1)
			philo[i].fk2 = 0;
		else
			philo[i].fk2 = i + 1;
		pthread_mutex_init(&data->fks[i], NULL);
		philo[i].id = i + 1;
		philo[i].meal_count = 0;
		philo[i].last_meal = 0;
		i++;
	}
	i = 0;
}

void	*thread_init(t_philo *philo)
{
	int	i;

	i = 0;
	philo->data->time_start = timer();
	while (i < philo->data->n_philo)
	{
		even_odd(&philo[i]);
		pthread_create(&philo[i].thread, NULL, &routine, (void *)&philo[i]);
		i++;
	}
	i = 0;
	pthread_create(&philo->data->monitoring, NULL, &monitor, (void *)philo);
	while (i < philo->data->n_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_join(philo->data->monitoring, NULL);
	return (NULL);
}
