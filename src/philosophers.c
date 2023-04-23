/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:07:57 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/22 22:54:41 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_data *db(void)
{
	static t_data data;

	return (&data);
}

int	valid_inputs(void)
{
	if (db()->philo == -1 || db()->die == -1 || db()->eat == -1000 \
	|| db()->sleep == -1000 || db()->x_eat == -1)
		return (0);
	return (1);
}


int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		db()->philo = ft_atoi(argv[1]);
		db()->die = ft_atoi(argv[2]);
		db()->eat = ft_atoi(argv[3]);
		db()->sleep = ft_atoi(argv[4]);
		if (argc == 6)
			db()->x_eat = ft_atoi(argv[5]);
		else
			db()->x_eat = -2;
		if (valid_inputs())
		{
			gettimeofday(&(db()->tv), NULL);
			db()->time_start = (long long)((db()->tv).tv_sec * 1000000 + (db()->tv).tv_usec) / 1000;
			start_threads();
		}
	}
	else
		printf("Something is not right...\n");
	return (0);
}
