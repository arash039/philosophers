/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:52:56 by ashojach          #+#    #+#             */
/*   Updated: 2023/08/17 23:30:29 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	eat(t_philo *philo)
{
	if (check_death(philo->data) == 1)
		return ;
	pthread_mutex_lock(&philo->data->fks[fk_lock_1(philo->fk1, philo->fk2)]);
	pthread_mutex_lock(&philo->data->fks[fk_lock_2(philo->fk1, philo->fk2)]);
	printer(philo, "has taken a fork");
	printer(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->meal_count);
	(*philo).meal_count += 1;
	pthread_mutex_unlock(&philo->data->meal_count);
	printer(philo, "is eating");
	usleep((*philo).data->t_eat * 1000);
	pthread_mutex_lock(&philo->data->lastmeal);
	philo->last_meal = timer();
	pthread_mutex_unlock(&philo->data->lastmeal);
	pthread_mutex_unlock(&philo->data->fks[fk_lock_1(philo->fk1, philo->fk2)]);
	pthread_mutex_unlock(&philo->data->fks[fk_lock_2(philo->fk1, philo->fk2)]);
} */

void	eat(t_philo *philo)
{
	if (check_death(philo->data) == 1)
		return ;
	pthread_mutex_lock(&philo->data->fks[fk_lock_1(philo->fk1, philo->fk2)]);
	pthread_mutex_lock(&philo->data->fks[fk_lock_2(philo->fk1, philo->fk2)]);
	printer(philo, "has taken a fork");
	printer(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->meal_count);
	(*philo).meal_count += 1;
	pthread_mutex_unlock(&philo->data->meal_count);
	printer(philo, "is eating");
	pthread_mutex_lock(&philo->data->lastmeal);
	philo->last_meal = timer();
	pthread_mutex_unlock(&philo->data->lastmeal);
	usleep((*philo).data->t_eat * 1000);
	pthread_mutex_unlock(&philo->data->fks[fk_lock_1(philo->fk1, philo->fk2)]);
	pthread_mutex_unlock(&philo->data->fks[fk_lock_2(philo->fk1, philo->fk2)]);
}

void	sleeping(t_philo *philo)
{
	if (check_death(philo->data) == 1)
		return ;
	printer(philo, "is sleeping");
	usleep((*philo).data->t_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	if (check_death(philo->data) == 1)
		return ;
	printer(philo, "is thinking");
}

void	*routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	if (philo->last_meal == 0)
		philo->last_meal = timer();
	while (!check_death(philo->data) || !end_check(philo))
	{
		eat(philo);
		if (check_death(philo->data) || end_check(philo))
			break ;
		sleeping(philo);
		if (check_death(philo->data) || end_check(philo))
			break ;
		thinking(philo);
	}
	return (NULL);
}
