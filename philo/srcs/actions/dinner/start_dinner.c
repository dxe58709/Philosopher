/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:06:40 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/11 17:13:04 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	start_dinner(t_data *data)
{
	if (!create_philosopher_threads(data))
	{
		print_error("Cannot create threads.\n");
		return (false);
	}
	return (true);
}
