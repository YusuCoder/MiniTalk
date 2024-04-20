/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:30:24 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/20 13:04:12 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (negative * result);
}

int	pid_validation(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	sig_handler(int pid, unsigned char c)
{
	int				i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << (7 - i)))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf(COLOR_RED"Error sending SIGUSR1\n"RESET);
				return ;
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf(COLOR_RED"Error sending SIGUSR2\n"RESET);
				return ;
			}
		}
		i++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 1 || pid_validation(argv[1]))
		{
			ft_printf(COLOR_RED "Error! Please retype the PID!\n"RESET);
			return (1);
		}
		while (argv[2][i])
		{
			sig_handler(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf(COLOR_YELLOW"Manual to use: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	return (0);
}
