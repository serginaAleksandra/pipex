/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:15:39 by asergina          #+#    #+#             */
/*   Updated: 2025/06/14 12:35:17 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils/ft_printf.h"
#include "libft.h"
#include <stdarg.h>

static int	process_format(const char *format, va_list arg, int *len);
static int	print_arg(char conv, va_list arg);
int			check_add(int *len, int res);
int			print_char(char c);

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	arg;

	if (!format)
		return (-1);
	len = 0;
	va_start(arg, format);
	if (process_format(format, arg, &len) == -1)
		return (va_end(arg), -1);
	va_end(arg);
	return (len);
}

static int	process_format(const char *format, va_list arg, int *len)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			if (check_add(len, print_char(format[i])) == -1)
				return (-1);
		}
		else if (format[i + 1])
		{
			i++;
			if (check_add(len, print_arg(format[i], arg)) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	check_add(int *len, int res)
{
	if (res < 0)
		return (-1);
	*len += res;
	return (0);
}

static int	print_arg(char conv, va_list arg)
{
	int	print_len;

	print_len = 0;
	if (conv == 'c')
		print_len += print_char(va_arg(arg, int));
	else if (conv == 's')
		print_len += print_string(va_arg(arg, char *));
	else if (conv == 'd' || conv == 'i')
		print_len += print_dec(va_arg(arg, int));
	else if (conv == 'u')
		print_len += print_unsigned(va_arg(arg, unsigned int));
	else if (conv == 'p')
		print_len += print_pointer(va_arg(arg, void *));
	else if (conv == '%')
		print_len += print_char('%');
	else if (conv == 'x' || conv == 'X')
		print_len += print_hex(va_arg(arg, unsigned int), conv);
	else
	{
		print_len += print_char('%');
		print_len += print_char(conv);
	}
	if (print_len == -1)
		return (-1);
	return (print_len);
}

int	print_char(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}
