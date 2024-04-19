/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:30:24 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/19 21:55:53 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	recieved_message(int signal)
{
	if (signal == SIGUSR1)
		ft_printf(COLOR_GREEN"The characters has been received and printed!\n");
	else if (signal == SIGUSR2)
		ft_printf(COLOR_GREEN"The characters has been received and printed!\n");
	else
		ft_printf("Received unexpected signal: %d\n", signal);
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
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << (7 - i)))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf(COLOR_RED "Error sending SIGUSR1\n");
				return ;
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf(COLOR_RED "Error sending SIGUSR2\n");
				return ;
			}
		}
		i++;
		usleep(50);
	}
}

void	printing_str(void)
{
	struct sigaction	sa_newsignal;

	sa_newsignal.sa_handler = recieved_message;
	sa_newsignal.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsignal, NULL) == -1)
		ft_printf(COLOR_RED "There is an error! Please try again!");
	if (sigaction(SIGUSR2, &sa_newsignal, NULL) == -1)
		ft_printf(COLOR_RED "There is an error! Please try again!");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		printing_str();
		pid = ft_atoi(argv[1]);
		if (pid < 1 || pid_validation(argv[1]))
		{
			ft_printf(COLOR_RED "Error! Please retype the PID!\n");
			return (1);
		}
		while (argv[2][i] != '\0')
		{
			sig_handler(pid, argv[2][i++]);
		}
		sig_handler(pid, '\0');
	}
	else
	{
		ft_printf(COLOR_YELLOW "Manual to use: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	return (0);
}

