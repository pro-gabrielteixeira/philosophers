/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:07:57 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/07 23:28:35 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_data *db(void)
{
	static t_data data;

	return (&data);
}

void	*routine()
{
	for(int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock (&db()->mutex);
		db()->mails = db()->mails + 1;
		pthread_mutex_unlock(&db()->mutex);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	n;

	i = 0;
	n = atoi(argv[1]);
	db()->mails = 0;
	pthread_t	phi[n];
	pthread_mutex_init(&db()->mutex, NULL);
	while (i < n)
	{
		if (pthread_create(&phi[i], NULL, &routine, NULL) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (pthread_join(phi[i], NULL) != 0)
			return (1);
			i++;	
	}
	pthread_mutex_destroy(&db()->mutex);
	printf("Mails: %i\n", db()->mails);
	return (0);
}
