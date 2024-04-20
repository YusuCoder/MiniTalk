/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:43:51 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/20 16:15:08 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sighandler(int signal, siginfo_t *data, void *context)
{
	static int	counter;
	static char	c;

	(void)context;
	c <<= 1;
	if (signal == SIGUSR1)
		c = c | 1;
	counter++;
	if (counter == 8)
	{
		if (c != '\0')
			ft_printf(COLOR_MAGENTA ITALIC "%c" RESET, c);
		else
		{
			kill(data->si_pid, SIGUSR1);
		}
		c = 0;
		counter = 0;
	}
}

int	main(void)
{
	struct sigaction	s_action;

	ft_printf(COLOR_GREEN "The server PID is: ");
	ft_printf(COLOR_CYAN BOLD UNDERLINE "%d\n" RESET, getpid());
	s_action.sa_sigaction = &sighandler;
	s_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_action, NULL) == -1)
	{
		ft_printf(COLOR_RED"Error calling sigaction!\n"RESET);
		exit (1);
	}
	if (sigaction(SIGUSR2, &s_action, NULL) == -1)
	{
		ft_printf(COLOR_RED"Error calling sigaction!\n"RESET);
		exit (1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
