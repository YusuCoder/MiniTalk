/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:25:53 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/13 22:47:33 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_adress(long *p)
{
	size_t	i;
	int		a;
	int		ishex_result;

	i = (size_t)p;
	if (ft_putstr("0x") == -1)
		return (-1);
	a = 2;
	ishex_result = ft_ishex(i, 0, 0);
	if (ishex_result == -1)
		return (-1);
	a += ishex_result;
	return (a);
}
