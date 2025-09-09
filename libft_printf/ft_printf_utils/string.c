/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:53:25 by asergina          #+#    #+#             */
/*   Updated: 2025/06/17 15:53:29 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	int	len;

	if (!str)
	{
		if (write (1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	len = 0;
	while (*str)
	{
		if (check_add(&len, print_char(*str)) == -1)
			return (-1);
		str++;
	}
	return (len);
}
