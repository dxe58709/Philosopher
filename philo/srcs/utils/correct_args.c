/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:11:30 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 00:59:34 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	only_digit(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (false);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			print_error("Not a valid string.\n");
			exit_flag(data);
			return (false);
		}
		i++;
	}
	if (i == 0)
	{
		print_error("string is empty.\n");
		exit_flag(data);
		return (false);
	}
	return (true);
}

static bool	is_overflow(t_data *data, const char *str, int *result)
{
	long long	nb;

	nb = 0;
	while (*str != '\0')
	{
		nb = nb * 10 + (*str - '0');
		if (nb > INT_MAX)
		{
			print_error("value is overflow.\n");
			exit_flag(data);
			return (false);
		}
		str++;
	}
	*result = nb;
	return (true);
}

static bool	argv_value(t_data *data, int i, int result)
{
	if (i == 1 && !(0 < result && result <= 200))//philo_max 200
	{
		print_error("Wrong number_of_philo.\n");
		exit_flag(data);
		return (false);
	}
	else if ((2 <= i && i <= 5) && result < 1)
	{
		print_error("Argument is wrong.\n");
		exit_flag(data);
		return (false);
	}
	return (true);
}

bool	check_correct_args(int argc, char **argv, t_data *data)
{
	int	i;
	int	correct_arg;

	i = 1;
	while (i < argc)
	{
		if (!only_digit(data, argv[i]))
			return (false);
		if (!is_overflow(data, argv[i], &correct_arg))
			return (false);
		if (!argv_value(data, i, correct_arg))
			return (false);
		i++;
	}
	return (true);
}
