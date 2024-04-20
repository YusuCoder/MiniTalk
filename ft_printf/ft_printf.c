/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:28:52 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/03 15:49:26 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversions(va_list p_arg, char a)
{
	int	length;

	length = 0;
	if (a == 'c')
		length += ft_putchar(va_arg(p_arg, int));
	else if (a == 's')
		length += ft_putstr(va_arg(p_arg, char *));
	else if (a == 'p')
		length += ft_print_adress(va_arg(p_arg, void *));
	else if (a == 'd')
		length += ft_putnbr(va_arg(p_arg, int), length);
	else if (a == 'i')
		length += ft_putnbr(va_arg(p_arg, int), length);
	else if (a == 'u')
		length += ft_decimal(va_arg(p_arg, unsigned int), length);
	else if (a == 'x')
		length += ft_ishex(va_arg(p_arg, unsigned int), 0, length);
	else if (a == 'X')
		length += ft_ishex(va_arg(p_arg, unsigned int), 1, length);
	else if (a == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	p_arg;
	int		i;
	int		res;

	res = 0;
	i = 0;
	va_start(p_arg, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			res++;
		}
		else
		{
			res += conversions(p_arg, format[++i]);
			if (res == -1)
				break ;
		}
		i++;
	}
	va_end(p_arg);
	return (res);
}
