/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:29:50 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/17 23:26:03 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	finish_threads(void)
{
	int	i;

	i = 0;
	while (i < db()->philo)
	{
		pthread_join(db()->t_philo[i], NULL);
		i++;
	}
	i = 0;
	while (i < db()->philo)
	{	
		pthread_mutex_destroy(&db()->forks[i]);
		i++;
	}
}

void	start_threads(void)
{
	pthread_mutex_t	my_forks[db()->philo];
	pthread_t		phi[db()->philo];
	int				id[db()->philo];
	int				start_timer[db()->philo];
	int				i;

	i = 0;
	db()->philo_time = start_timer;
	db()->forks = my_forks;
	db()->t_philo = phi;
	while (i < db()->philo)
	{
		pthread_mutex_init(&db()->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < db()->philo)
	{
		id[i] = i + 1;
		pthread_create(&phi[i], NULL, routine, &id[i]);
		i++;
	}
	finish_threads();
}
