/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:44:25 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/17 23:25:02 by gateixei         ###   ########.fr       */
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
# include <time.h>

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_t		*t_philo;
	struct timeval	tv;
	long long		time_start;
	int				*philo_time;
	int				philo;
	int				die;
	int				eat;
	int				sleep;
	int				x_eat;
	int				turn;
	int				flag;
}   t_data;

//utils.c
int 	ft_atoi(char *str);

//routine.c
int	check_death(int id);
void	time_stamp(int id);
long long	time_manager(void);
void	action(int id, int fork_n);
void	*routine(void *arg);

//threads.c
void	finish_threads(void);
void	start_threads(void);

//philosophers.c
t_data	*db(void);
int		main(int argc, char **argv);

#endif