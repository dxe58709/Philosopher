/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:51:13 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 18:57:15 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>

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

//init
bool			init_mutex(pthread_mutex_t *mutex, unsigned int count);
bool			init_args(int argc, char **argv, t_philo *philo);
bool			check_init_philo_data(t_philo *philo);
bool			check_init_thread(t_data *data);

//destroy
void			destroy_mutex(pthread_mutex_t *mutex, unsigned int count);
void			delete_data(t_data *data);

#endif
