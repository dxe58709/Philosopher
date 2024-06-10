/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:37:07 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 18:18:12 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define PHILO_MAX 200

# include "dinner.h"
# include "utils.h"

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
	int				philo_id;
	int				count_eaten;
	unsigned int	last_meal_time;
	pthread_mutex_t	*left_fork_mtx;
	pthread_mutex_t	*right_fork_mtx;
	pthread_mutex_t	count_eaten_mtx;
	pthread_mutex_t	last_meal_time_mtx;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	t_args			args;
	t_philo			*philo;
	unsigned int	starting_time;
	bool			stop;
	pthread_mutex_t	stop_mtx;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	*forks_mtx;
	pthread_t		*threads;
	pthread_t		monitor;
}	t_data;

#endif
