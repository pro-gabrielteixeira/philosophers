/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:29:50 by gateixei          #+#    #+#             */
/*   Updated: 2023/06/08 15:29:58 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	free(db()->philo_time);
	free(db()->forks);
	free(db()->t_philo);
	free(db()->count);
	db()->philo_time = NULL;
	db()->forks = NULL;
	db()->t_philo = NULL;
	db()->count = NULL;
}

void	start_threads(void)
{
	int	*id;
	int	i;

	id = malloc(sizeof(int) * db()->philo);
	do_malloc();
	i = 0;
	while (i < db()->philo)
	{
		pthread_mutex_init(&db()->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&db()->m_flag, NULL);
	i = 0;
	while (i < db()->philo)
	{
		id[i] = i + 1;
		pthread_create(&db()->t_philo[i], NULL, routine, &id[i]);
		i++;
	}
	finish_threads();
	free(id);
	id = NULL;
}
