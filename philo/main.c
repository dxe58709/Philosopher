/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:22:53 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 17:41:01 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!init_args(argc, argv, &data))
		return (1);
	if (!init_philo(&data))
		return (1);
	if (!start_dinner(&data))
	{
		dalete_data(&data);
		return (1);
	}
	dalete_data(&data);
	return (0);
}
