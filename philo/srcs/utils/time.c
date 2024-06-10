/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:02:30 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 21:43:19 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned int	get_current_time(void)
{
	unsigned int	ms;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (ms);
}

unsigned int	update_last_meal_time(t_philo *philo)
{
	unsigned int	last_meal_time;

	pthread_mutex_lock(&philo->last_meal_time_mtx);
	philo->last_meal_time = get_current_time();
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_time_mtx);
	return (last_meal_time);
}

void	wait_for_action(t_philo *philo, time_t action_duration)
{
	time_t	action_time;

	action_time = get_current_time() + action_duration;

	while (get_current_time() < action_time)
	{
		if (check_philo_die(philo))
			return ;
		usleep(100);
	}
}
