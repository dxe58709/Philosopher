/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:41:37 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 19:00:55 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINNER_H
# define DINNER_H

# include "philo.h"
# include "utils.h"

//forks
void	take_forks(t_philo *philo);


//eat.c
void	philo_eating(t_data *data);

//think.c
void	philo_thinking(t_data *data);

//sleep.c
void	philo_sleeping(t_data *data);

#endif
