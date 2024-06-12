/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:37:07 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/12 17:46:16 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_args
{
	unsigned int	number_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				number_of_eat;
}	t_args;

typedef struct s_philo
{
	struct s_data	*data;
	int				philo_id;
	int				count_eaten;
	unsigned int	last_meal_time;
	pthread_mutex_t	*left_fork_mtx;
	pthread_mutex_t	*right_fork_mtx;
	pthread_mutex_t	count_eaten_mtx;
	pthread_mutex_t	last_meal_time_mtx;
}	t_philo;

typedef struct s_data
{
	t_args			args;
	t_philo			*philo;
	unsigned int	starting_time;
	pthread_t		*threads;
	pthread_t		monitor;
	bool			stop;
	pthread_mutex_t	stop_mtx;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	*forks_mtx;
}	t_data;

//forks
void			take_forks(t_philo *philo);
void			release_forks(t_philo *philo);

//eat.c
void			philo_eating(t_philo *philo);
void			count_eat(t_philo *philo);

//think.c
void			philo_thinking(t_philo *philo);

//sleep.c
void			philo_sleeping(t_philo *philo);

//threads
bool			create_thread(pthread_t *thread, void *(*routine)(void *),
					void *arg);
bool			join_thread(pthread_t thread);
bool			create_philosopher_threads(t_data *data);

//dinner
void			*philo_routine(void *args);
void			*one_philo(t_philo *philo);
bool			start_dinner(t_data *data);
void			*monitor_philos(void *args);

//utils
int				philo_atoi(char *str);
void			*ft_calloc(size_t count, size_t size);

//print
void			print_error(char *str);
void			print_message(char *str, t_philo *philo);

//time.c
unsigned int	get_current_time(void);
void			wait_for_action(t_philo *philo, time_t action_duration);

//stop.c
bool			check_philo_die(t_data *data);
void			set_stop(t_data *data);
bool			can_continue_routine(t_philo *philo);

//init
bool			init_mutex(pthread_mutex_t *mutex, unsigned int count);
bool			init_args(int argc, char **argv, t_data *data);
bool			can_init_philo_data(t_data *data);
bool			can_init_thread(t_data *data);

//destroy
void			destroy_mutex(pthread_mutex_t *mutex, unsigned int count);
void			delete_data(t_data *data);

#endif
