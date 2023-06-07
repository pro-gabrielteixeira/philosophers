/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:27:02 by gateixei          #+#    #+#             */
/*   Updated: 2023/06/05 21:29:12 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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

int ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
        printf("Just positive numbers, please!\n");
        return (-1);
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		res = (res * 10) - (str[i] - '0');
        if (str[i] < '0' || str[i] > '9')
        {
            printf("Just numbers, please!\n");
            return (-1);
        }
		i++;
	}
	return (res * -1);
}