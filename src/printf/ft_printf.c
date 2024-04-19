/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:08:23 by hclaude           #+#    #+#             */
/*   Updated: 2024/04/19 23:28:50 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_printf_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, unsigned int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'p')
		count += ft_putpointer(va_arg(ap, void *));
	else if (c == 'x' || c == 'X')
		count += ft_hexadecimal(va_arg(ap, unsigned int), c);
	else if (c == '%')
		count += ft_putchar(c);
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	return (count);
}

/* 
 * Writes the string pointed by 'format' to the standard output (stdout). 
 * If format includes format specifiers (subsequences beginning with %), 
 * the additional arguments following format are formatted and inserted 
 * in the resulting string replacing their respective specifiers.
 * @param format This is the string that contains the text to be 
 * written to stdout. 
 * It can optionally contain embedded format specifiers that are replaced 
 * by the values specified in subsequent additional 
 * arguments and formatted as requested.
 * @return Upon successful return, 
 * these function return the number of characters printed 
 * (excluding the null byte used to end output to strings). 
 * If an output error is encountered, a negative value is returned.
 */
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (!format)
		return (0);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_printf_format(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
