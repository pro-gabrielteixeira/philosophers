/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:29:50 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/17 00:42:47 by gateixei         ###   ########.fr       */
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
		pthread_mutex_destroy(&db()->forks[i]);
		i++;	
	}
	free(db()->forks);
	free(db()->t_philo);
}

void	start_threads(void)
{
	pthread_mutex_t	*my_forks;
	pthread_t		*phi;
	int				id[db()->philo];
	int				i;

	i = 0;
	my_forks = malloc(sizeof(pthread_mutex_t) * (db()->philo));
	phi = malloc(sizeof(pthread_t) * (db()->philo));
	db()->forks = my_forks;
	db()->t_philo = phi;
	while (i < db()->philo)
	{
		if (pthread_mutex_init(&db()->forks[i], NULL) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < db()->philo)
	{
		id[i] = i + 1;
		if (pthread_create(&phi[i], NULL, routine, &id[i]) != 0)
			return ;
		i++;
	}
	finish_threads();
}