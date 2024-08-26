/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:59:54 by ashojach          #+#    #+#             */
/*   Updated: 2023/08/17 21:12:43 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data
{
	pthread_t		monitoring;
	pthread_mutex_t	timewarp;
	pthread_mutex_t	meal_count;
	pthread_mutex_t	m_end;
	pthread_mutex_t	print;
	pthread_mutex_t	lastmeal;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	*fks;
	int				n_philo;
	int				n_must_eat;
	int				t_sleep;
	int				t_eat;
	int				t_die;
	int				n_end;
	int				dead;
	int				end;
	long long		time_start;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				fk1;
	int				fk2;
	t_data			*data;
	long long		last_meal;
	int				id;
	int				meal_count;
}	t_philo;

int			fk_lock_2(int dx, int sx);
int			fk_lock_1(int sx, int dx);
int			check_death(t_data *data);
void		*monitor(void *ph);
int			philo_is_dead(t_philo *philo);
long long	delta_time(long long time);
long long	timer(void);
void		*routine(void *ph);
void		eat(t_philo *philo);
void		sleeping(t_philo *philo);
void		even_odd(t_philo *philo);
void		thinking(t_philo *philo);
void		printer(t_philo *philo, char *str);
void		destroy(t_philo *philo);
int			ft_atoi(char *num);
int			ft_isdigit(char *str);
int			ft_check_args(int ac, char **av);
int			finish_check(t_philo *philo);
void		mutex_init(t_data *data);
int			ft_print_error(int i);
void		one_philo(t_philo *philo);
void		data_init(int ac, char **av, t_data *data);
int			die_cal(t_philo *philo, long long die_t, long long t_now);
int			end_check(t_philo *philo);
void		*thread_init(t_philo *philo);
void		philo_init(t_philo *philo, t_data *dt);

#endif
