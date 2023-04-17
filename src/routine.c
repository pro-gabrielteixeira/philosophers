/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:38:17 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/18 00:06:12 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_death(int id)
{
	int	i;

	// usleep(id * 100);
	if (db()->flag == 1)
	{
		printf("RETURN ID %i\n", id);
		return (1);
	}
	i = (int) time_manager() - (db()->philo_time[id - 1]);
	if (i >= db()->die)
	{
		printf("%lld %i \033[31mdied\033[0m\n", time_manager(), id);
		db()->flag = 1;
		return (1);
	}
	return (0);
}

void	time_stamp(int id)
{
	db()->philo_time[id - 1] = (int) time_manager();
}

long long	time_manager(void)
{
	long long	time_now;
	gettimeofday(&(db()->tv), NULL);
	time_now = (long long)(((db()->tv).tv_sec * 1000000 + (db()->tv).tv_usec) / 1000) - db()->time_start;
	return (time_now);
}

void	action(int id, int fork_n)
{
	while (TRUE)
	{
		while (db()->turn == 0 && (id % 2) == 0)
			if (check_death(id))
				return ;
		while (db()->turn == 1 && (id % 2) != 0)
			if (check_death(id))
				return ;
		pthread_mutex_lock(&db()->forks[id - 1]);
		printf("%lld ms %i\033[32m has taken a fork\033[0m\n", time_manager(), id);
		pthread_mutex_lock(&db()->forks[fork_n]);
		printf("%lld ms %i\033[32m is eating (FORK %i AND %i)\033[0m\n", time_manager(), id, fork_n, id - 1);
		usleep(db()->eat);
		if (id == 1)
			db()->turn++;
		else if (id == 2)
			db()->turn--;
		time_stamp(id);
		pthread_mutex_unlock(&db()->forks[id - 1]);
		pthread_mutex_unlock(&db()->forks[fork_n]);
		// if (check_death(id))
		// 	return ;
		printf("%lld ms %i\033[33m is sleeping\033[0m\n", time_manager(), id);
		usleep(db()->sleep);
		// if (check_death(id))
		// 	return ;
		printf("%lld ms %i\033[33m is thinking\033[0m\n", time_manager(), id);
	}
}

// void	action(int id, int fork_n)
// {
// 	while (db()->turn == 0 && (id % 2) == 0)
// 		if (check_death(id))
// 			return ;
// 	while (db()->turn == 1 && (id % 2) != 0)
// 		if (check_death(id))
// 			return ;
// 	pthread_mutex_lock(&db()->forks[id - 1]);
// 		if (check_death(id))
// 			return ;
// 	printf("%lld ms %i\033[32m has taken a fork\033[0m\n", time_manager(), id);
// 	pthread_mutex_lock(&db()->forks[fork_n]);
// 		if (check_death(id))
// 			return ;
// 	printf("%lld ms %i\033[32m is eating (FORK %i AND %i)\033[0m\n", time_manager(), id, fork_n, id - 1);
// 	usleep(db()->eat);
// 	time_stamp(id);
// 	if (id == 1)
// 		db()->turn++;
// 	else if (id == 2)
// 		db()->turn--;
// 	if (check_death(id))
// 		return ;
// 	printf("%lld ms %i\033[33m is sleeping\033[0m\n", time_manager(), id);
// 	pthread_mutex_unlock(&db()->forks[id - 1]);
// 	pthread_mutex_unlock(&db()->forks[fork_n]);
// 	usleep(db()->sleep);
// 	if (check_death(id))
// 		return ;
// 	printf("%lld ms %i\033[33m is thinking\033[0m\n", time_manager(), id);
// 	action(id, fork_n);
// }

void	*routine(void *arg)
{
	int	id;
	int fork_n;

	id = *((int*)arg);
	if (id == db()->philo)
		fork_n = 0;
	else
		fork_n = id;
	db()->turn = 0;
	db()->flag = 0;
	time_stamp(id);
	action(id, fork_n);
}

// void	*routine(void *arg)
// {
// 	int	id;
// 	int fork_odd;
// 	int fork_even;

// 	id = *((int*)arg);
// 	if ((id % 2) == 0)
// 	{
// 		if (id == db()->philo)
// 			fork_even = 0;
// 		else
// 			fork_even = id;
// 		fork_odd = id - 1;
// 	}
// 	else
// 	{
// 		if (id == db()->philo)
// 			fork_odd = 0;
// 		else
// 			fork_odd = id;
// 		fork_even = id - 1;
// 	}
// 	db()->turn = 0;
// 	time_stamp(id);
// 	action(id, fork_even, fork_odd);
// }