/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:15:40 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/13 22:16:39 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_thread(pthread_t *thread, void *(*routine)(void *),
		void *arg)
{
	if (pthread_create(thread, NULL, routine, arg) != 0)
		return (false);
	return (true);
}

bool	join_thread(pthread_t thread)
{
	if (pthread_join(thread, NULL) != 0)
		return (false);
	return (true);
}
