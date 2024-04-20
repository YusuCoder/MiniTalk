/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:44:53 by ryusupov          #+#    #+#             */
/*   Updated: 2024/03/20 12:46:27 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int c, int *res)
{
	int	recursive_result;

	recursive_result = 0;
	if (c < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		c *= -1;
		(*res)++;
	}
	if (c > 9)
	{
		recursive_result = ft_putnbr(c / 10, 0);
		if (recursive_result == -1)
			return (-1);
		(*res) += recursive_result;
	}
	if (ft_putchar(c % 10 + '0') == -1)
		return (-1);
	(*res)++;
	return (0);
}

int	ft_putnbr(int c, int res)
{
	int	print_result;

	if (c == -2147483648)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		res = 11;
	}
	else
	{
		print_result = print_number(c, &res);
		if (print_result == -1)
			return (-1);
	}
	return (res);
}
