/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:49:31 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 20:12:44 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_thinking(t_philo *philo)
{
	time_t	think_time;

	print_message("is thinking", philo);
	think_time = philo->data->args.time_to_eat * 2
		- philo->data->args.time_to_sleep;
	if ((philo->data->args.number_of_philo % 2)
		&& !check_philo_die(philo->data))
		wait_for_action(philo, think_time);
}
