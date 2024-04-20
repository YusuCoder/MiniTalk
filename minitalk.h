/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:11:04 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/20 21:03:17 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
//ANSI COLOR SET
# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_BLUE "\x1b[24m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_WHITE "\x1b[97m"
# define RESET "\x1b[0m"
//ANSI TEXT STYLE
# define BOLD "\x1b[1m"
# define UNDERLINE "\x1b[4m"
# define ITALIC "\x1b[3m"
# define RESET "\x1b[0m"
//LIBS
# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

#endif
