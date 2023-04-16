/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:44:25 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/17 00:20:09 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_t		*t_philo;
	int				philo;
	int				die;
	int				eat;
	int				sleep;
	int				x_eat;
}   t_data;

//utils.c
int 	ft_atoi(char *str);

//routine.c
void	actions_odd(int id, int fork_n);
void	actions_even(int id, int fork_n);
void	*routine(void *arg);

//threads.c
void	finish_threads(void);
void	start_threads(void);

//philosophers.c
t_data	*db(void);
int		main(int argc, char **argv);

#endif