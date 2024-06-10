/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:41:37 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 21:32:46 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINNER_H
# define DINNER_H

# include "philo.h"
# include "utils.h"

//forks
void	take_forks(t_philo *philo);
void	release_forks(t_philo *philo);

//eat.c
void	philo_eating(t_data *data);
void	count_eat(t_philo *philo);

//think.c
void	philo_thinking(t_data *data);

//sleep.c
void	philo_sleeping(t_data *data);

//threads
bool	create_thread(pthread_t *thread, void *(*routine)(void *),
			void *arg);
bool	join_thread(pthread_t thread);

//dinner
void	*philo_routine(void *args);
void	*one_philo(t_philo *philo);

#endif
