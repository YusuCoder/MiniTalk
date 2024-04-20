/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:16:30 by ryusupov          #+#    #+#             */
/*   Updated: 2024/03/22 12:58:11 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *input, ...);
int		ft_putstr(char *c);
int		ft_putnbr(int c, int res);
int		ft_putchar(char s);
int		ft_print_adress(long *p);
int		ft_decimal(size_t i, int res);
int		ft_ishex(unsigned long long hex, int num, char uc);
size_t	ft_strlen(const char *str);

#endif
