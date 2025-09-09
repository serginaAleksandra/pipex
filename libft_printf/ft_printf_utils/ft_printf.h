/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:20:13 by asergina          #+#    #+#             */
/*   Updated: 2025/06/14 12:20:31 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	print_char(char c);
int	print_string(char *str);
int	print_dec(int d);
int	print_unsigned(unsigned int u);
int	print_pointer(void *adress);
int	print_hex(unsigned long n, char conv);
int	check_add(int *len, int res);

#endif
