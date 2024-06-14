/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:24:07 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 21:37:14 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_args(int argc, char **argv, t_data *data)
{
	data->args.number_of_philo = philo_atoi(argv[1]);
	data->args.time_to_die = philo_atoi(argv[2]);
	data->args.time_to_eat = philo_atoi(argv[3]);
	data->args.time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		data->args.number_of_eat = philo_atoi(argv[5]);
	else
		data->args.number_of_eat = -1;
	return (true);
}

bool	can_init_args(int argc, char **argv, t_data *data)
{
	if (!init_args(argc, argv, data))
	{
		print_error("Failed to initialize arguments.\n");
		return (false);
	}
	return (true);
}
