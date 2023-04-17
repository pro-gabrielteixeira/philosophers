/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:27:02 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/17 19:07:44 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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