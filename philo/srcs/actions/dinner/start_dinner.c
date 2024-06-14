/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:06:40 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 15:41:54 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	start_dinner(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->starting_time = get_current_time();
	while (i < data->args.number_of_philo)
	{
		if (!create_thread(&data->threads[i], &philo_routine, &data->philo[i]))
		{
			print_error("Failed to create threads.\n");
			return ;
		}
		i++;
	}
	if (data->args.number_of_philo > 1)
	{
		if (!create_thread(&data->monitor, monitor_philos, data))
		{
			print_error("Failed to create monitor threads.\n");
			return ;
		}
	}
}

// void start_dinner(t_data *data)
// {
//     unsigned int i;

//     for (i = 0; i < data->args.number_of_philo; i++)
//     {
//         if (!create_thread(&data->threads[i], &philo_routine, &data->philo[i]))
//         {
//             for (unsigned int j = 0; j < i; j++)
//                 pthread_join(data->threads[j], NULL);
//             return;
//         }
//     }

//     if (!create_thread(&data->monitor, monitor_philos, data))
//     {
//         for (unsigned int j = 0; j < data->args.number_of_philo; j++)
//             pthread_join(data->threads[j], NULL);
//         return;
//     }
// }