/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:08:16 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 18:26:06 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_intmax(int nb)
{
	return (nb > INT_MAX / 10 || (nb == INT_MAX / 10 && nb > INT_MAX % 10));
}

int	philo_atoi(char *str)
{
	int	nb;
	int	flag;

	nb = 0;
	flag = -1;
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (ft_intmax(nb))
			return (flag);
		nb = nb * 10 + *str - '0';
		str++;
	}
	if (*str != '\0')
		return (flag);
	return (nb);
}
