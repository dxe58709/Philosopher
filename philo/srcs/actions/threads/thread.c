/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:15:40 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/13 17:28:21 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_thread(pthread_t *thread, void *(*routine)(void *),
		void *arg)
{
	if (pthread_create(thread, NULL, routine, arg) != 0)
	{
		print_error("Failed to create thread\n");
		return (false);
	}
	return (true);
}

bool	join_thread(pthread_t thread)
{
	if (pthread_join(thread, NULL) != 0)
	{
		print_error("Failed to join thread\n");
		return (false);
	}
	return (true);
}
