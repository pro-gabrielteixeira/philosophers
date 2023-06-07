/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:44:25 by gateixei          #+#    #+#             */
/*   Updated: 2023/06/05 19:09:10 by gateixei         ###   ########.fr       */
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
	pthread_mutex_t	m_flag;
	pthread_t		*t_philo;
	struct timeval	tv;
	long long		time_start;
	int				*philo_time;
	int				philo;
	int				die;
	int				eat;
	int				sleep;
	int				x_eat;
	int				*count;
	int				flag;
}   t_data;

// utils.c
int 	ft_atoi(char *str);

// routine.c
int	check_death(int id, int fork_odd, int fork_even);
void	time_stamp(int id);
long long	time_manager(void);
void	action_sleep(int id, int fork_odd, int fork_even);
void	action_eat(int id, int fork_odd, int fork_even);
void	*routine(void *arg);

// threads.c
// void	finish_threads(void);
void	start_threads(void);

// philosophers.c
t_data	*db(void);
int		main(int argc, char **argv);

#endif