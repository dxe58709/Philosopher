/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relese_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:47:29 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 19:10:36 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dinner.h"

void	release_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork_mtx);
		pthread_mutex_unlock(philo->right_fork_mtx);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork_mtx);
		pthread_mutex_unlock(philo->left_fork_mtx);
	}
}
