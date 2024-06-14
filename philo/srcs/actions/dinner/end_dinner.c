/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:22:02 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 15:40:51 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_dinner(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->args.number_of_philo)
	{
		if (!join_thread(data->threads[i]))
		{
			print_error("Failed to join philo threads.\n");
			exit_flag(data);
			return ;
		}
		i++;
	}
	if (data->args.number_of_philo > 1)
	{
		if (!join_thread(data->monitor))
		{
			print_error("Failed to join monitor threads.\n");
			exit_flag(data);
			return ;
		}
	}
}
