/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:44:26 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 19:00:22 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dinner.h"

void	take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork_mtx);
		print_message("has taken a fork", philo);
		pthread_mutex_lock(philo->right_fork_mtx);
		print_message("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork_mtx);
		print_message("has taken a fork", philo);
		pthread_mutex_lock(philo->left_fork_mtx);
		print_message("has taken a fork", philo);
	}
}
