/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:09:09 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/11 16:15:58 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*char_ptr;
	size_t	n;

	if (count && size && size > SIZE_MAX / count)
		return (NULL);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(size * count);
	if (ptr == NULL)
	{
		print_error("Cannot allocate memory.\n");
		return (NULL);
	}
	char_ptr = (char *)ptr;
	n = count * size;
	while (n--)
		*char_ptr++ = '\0';
	return (ptr);
}
