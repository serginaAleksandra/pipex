/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:17:26 by asergina          #+#    #+#             */
/*   Updated: 2025/06/14 12:30:32 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int	print_unsigned(unsigned int n)
{
	int		len;
	int		tmp;
	char	c;

	len = 0;
	if (n >= 10)
	{
		tmp = print_unsigned(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	c = n % 10 + '0';
	tmp = print_char(c);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}

int	print_dec(int d)
{
	char	*nb;
	int		print_len;

	print_len = 0;
	nb = ft_itoa(d);
	if (nb == NULL)
		return (-1);
	print_len = print_string(nb);
	free(nb);
	if (print_len == -1)
		return (-1);
	return (print_len);
}
