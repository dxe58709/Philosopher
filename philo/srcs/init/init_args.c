/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:24:07 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 17:54:53 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_args(int argc, char **argv, t_data *data)
{
	if (!(argc == 5 || argc == 6))
	{
		print_error("argc is wrong.\n");
		return (false);
	}
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
