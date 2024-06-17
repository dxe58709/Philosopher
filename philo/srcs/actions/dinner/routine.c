/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:21:08 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/17 21:16:14 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_continue_routine(t_philo *philo)
{
	if (!check_philo_die(philo->data))
	{
		if (philo->data->args.number_of_eat < 0)
			return (true);
		if (philo->count_eaten < philo->data->args.number_of_eat)
			return (true);
	}
	return (false);
}

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->data->args.number_of_philo == 1)
	{
		if (philo->data->args.number_of_eat != -1)
		{
			print_error("No one philosopher can number_of_eat.\n");
			return (NULL);
		}
		return (one_philo(philo));
	}
	while (check_continue_routine(philo))
	{
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (NULL);
}
