/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:22:53 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/12 17:48:31 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!can_init_thread(&data))
		return (1);
	if (!init_args(argc, argv, &data))
		return (1);
	if (!can_init_philo_data(&data))
		return (1);
	if (!start_dinner(&data))
	{
		delete_data(&data);
		return (1);
	}
	delete_data(&data);
	return (0);
}
