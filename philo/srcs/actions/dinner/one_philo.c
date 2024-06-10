/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:26:01 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 19:38:26 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dinner.h"

void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mtx);
	print_message("has taken a fork", philo);
	print_message("is thinking", philo);
	wait_for_action(philo, philo->data->args.time_to_die);
	print_message("died", philo);
	pthread_mutex_unlock(philo->left_fork_mtx);
	return (NULL);
}
