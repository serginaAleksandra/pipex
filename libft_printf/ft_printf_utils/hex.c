/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:16:33 by asergina          #+#    #+#             */
/*   Updated: 2025/06/14 12:52:54 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex(unsigned long n, const char conv)
{
	char	*base;
	char	*bbase;
	int		len;
	int		tmp;

	base = "0123456789abcdef";
	bbase = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
	{
		tmp = put_hex(n / 16, conv);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (conv == 'x')
		tmp = print_char(base[n % 16]);
	else if (conv == 'X')
		tmp = print_char(bbase[n % 16]);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}

int	print_hex(unsigned long n, const char conv)
{
	if (n == 0)
	{
		if (print_char('0') == -1)
			return (-1);
		return (1);
	}
	else
		return (put_hex(n, conv));
}

int	print_pointer(void *adress)
{
	unsigned long	adress_n;
	int				len;

	adress_n = (unsigned long)adress;
	len = 0;
	if (adress_n == 0)
	{
		len = write (1, "(nil)", 5);
		if (len < 0)
			return (-1);
		return (len);
	}
	if (check_add(&len, write (1, "0x", 2)) == -1)
		return (-1);
	if (check_add(&len, print_hex(adress_n, 'x')) == -1)
		return (-1);
	return (len);
}
