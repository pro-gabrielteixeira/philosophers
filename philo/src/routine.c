/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:38:17 by gateixei          #+#    #+#             */
/*   Updated: 2023/06/08 15:30:01 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_death(int id, int fork_odd, int fork_even)
{
	int	i;

	usleep(300);
	pthread_mutex_lock(&db()->m_flag);
	if (db()->flag == 1)
	{
		pthread_mutex_unlock(&db()->m_flag);
		pthread_mutex_unlock(&db()->forks[fork_even]);
		pthread_mutex_unlock(&db()->forks[fork_odd]);
		return (1);
	}
	i = (int) time_manager() - (db()->philo_time[id - 1]);
	if (i >= db()->die)
	{
		printf("%lld %i \033[31mdied\033[0m\n", time_manager(), id);
		db()->flag = 1;
		pthread_mutex_unlock(&db()->m_flag);
		pthread_mutex_unlock(&db()->forks[fork_even]);
		pthread_mutex_unlock(&db()->forks[fork_odd]);
		return (1);
	}
	pthread_mutex_unlock(&db()->m_flag);
	return (0);
}

void	action_sleep(int id, int fork_odd, int fork_even)
{
	printf("%lld %i\033[33m is sleeping\033[0m\n", time_manager(), id);
	pthread_mutex_unlock(&db()->forks[fork_odd]);
	pthread_mutex_unlock(&db()->forks[fork_even]);
	while (((int) time_manager() - (db()->philo_time[id - 1])) \
	< (db()->eat + db()->sleep))
		if (check_death(id, fork_odd, fork_even))
			return ;
	printf("%lld %i\033[33m is thinking\033[0m\n", time_manager(), id);
	action_eat(id, fork_odd, fork_even);
}

void	action_eat(int id, int fork_odd, int fork_even)
{
	if (db()->count[id - 1] != 0)
		db()->count[id - 1]--;
	else
		return ;
	pthread_mutex_lock(&db()->forks[fork_even]);
	if (check_death(id, fork_odd, fork_even))
		return ;
	printf("%lld %i\033[32m has taken a fork\033[0m\n", time_manager(), id);
	if (db()->philo == 1)
	{
		usleep(db()->die * 1000);
		printf("%lld %i \033[31mdied\033[0m\n", time_manager(), id);
		return ;
	}
	pthread_mutex_lock(&db()->forks[fork_odd]);
	time_stamp(id);
	printf("%lld %i\033[32m is eating\033[0m\n", time_manager(), id);
	while (((int) time_manager() - (db()->philo_time[id - 1])) < db()->eat)
		if (check_death(id, fork_odd, fork_even))
			return ;
	action_sleep(id, fork_odd, fork_even);
}

void	*routine(void *arg)
{
	int	id;
	int	fork_odd;
	int	fork_even;

	id = *((int *)arg);
	if ((id % 2) == 0)
	{
		if (id == db()->philo)
			fork_even = 0;
		else
			fork_even = id;
		fork_odd = id - 1;
		usleep(5);
	}
	else
	{
		if (id == db()->philo)
			fork_odd = 0;
		else
			fork_odd = id;
		fork_even = id - 1;
	}
	time_stamp(id);
	action_eat(id, fork_odd, fork_even);
	return (NULL);
}
