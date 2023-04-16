/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:07:57 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/16 23:55:43 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_data *db(void)
{
	static t_data data;

	return (&data);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
	db()->philo = ft_atoi(argv[1]);
	db()->die = (ft_atoi(argv[2]) * 1000);
	db()->eat = (ft_atoi(argv[3]) * 1000);
	db()->sleep = (ft_atoi(argv[4]) * 1000);
	if (argc == 6)
		db()->x_eat = ft_atoi(argv[5]);
	start_threads();
	}
	return (0);
}
