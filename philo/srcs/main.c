/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:22:53 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 21:21:55 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!can_dinner(&data, argc, argv))
	{
		delete_data(&data);
		return (1);
	}
	start_dinner(&data);
	end_dinner(&data);
	delete_data(&data);
	return (0);
}
