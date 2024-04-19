/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:43:51 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/19 21:11:24 by ryusupov         ###   ########.fr       */
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
			ft_printf(COLOR_MAGENTA ITALIC "%c", c);
		else
			kill(data->si_pid, SIGUSR1);
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
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
