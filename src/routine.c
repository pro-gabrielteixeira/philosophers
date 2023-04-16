/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:38:17 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/17 00:18:29 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	actions_odd(int id, int fork_n)
{
	if (!(pthread_mutex_lock(&db()->forks[fork_n])))
	{
		printf("%i\033[32m has taken a fork\033[0m\n", id);
		if (!(pthread_mutex_lock(&db()->forks[id - 1])))
		{	
			printf("%i\033[32m is eating\033[0m\n", id);
			usleep(db()->eat);
			pthread_mutex_unlock(&db()->forks[id - 1]);
		}
		pthread_mutex_unlock(&db()->forks[fork_n]);
	}
	printf("%i\033[33m is sleeping\033[0m\n", id);
	usleep(db()->sleep);	
	printf("%i\033[33m is thinking\033[0m\n", id);
	actions_odd(id, fork_n);
}

void	actions_even(int id, int fork_n)
{
	if (!(pthread_mutex_lock(&db()->forks[id - 1])))
	{
		printf("%i\033[32m has taken a fork\033[0m\n", id);
		if (!(pthread_mutex_lock(&db()->forks[fork_n])))
		{	
			printf("%i\033[32m is eating\033[0m\n", id);
			usleep(db()->eat);
			pthread_mutex_unlock(&db()->forks[fork_n]);
		}
		pthread_mutex_unlock(&db()->forks[id - 1]);
	}
	printf("%i\033[33m is sleeping\033[0m\n", id);
	usleep(db()->sleep);	
	printf("%i\033[33m is thinking\033[0m\n", id);
	actions_even(id, fork_n);
}

void	*routine(void *arg)
{
	int	id;
	int fork_n;

	id = *((int*)arg);
	if (id == db()->philo)
		fork_n = 0;
	else
		fork_n = id;
	if ((id % 2) == 0)
		actions_even(id, fork_n);
	else
		actions_odd(id, fork_n);
}