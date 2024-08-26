/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:57:06 by ashojach          #+#    #+#             */
/*   Updated: 2023/08/17 23:06:42 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fk_lock_1(int s1, int s2)
{
	if (s1 < s2)
		return (s1);
	return (s2);
}

int	fk_lock_2(int s1, int s2)
{
	if (s1 < s2)
		return (s2);
	return (s1);
}

void	even_odd(t_philo *philo)
{
	int	j;

	j = 0;
	if (philo->data->n_philo % 2 == 0)
		j = 0;
	else
		j = 1;
	if (philo->id % 2 == 0 && j == 0)
		usleep(100);
	if (philo->id % 2 == 1 && j == 1)
		usleep(100);
	return ;
}
