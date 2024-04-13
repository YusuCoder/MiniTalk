/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:43:51 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/13 22:26:27 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int signal)
{
	static int	counter;
	static char	c;
	static int	pid;

	if (!pid)
		pid = getpid();
	c <<= 1;
	if (signal == SIGUSR1)
		c = c | 1;
	counter++;
	if (counter == 8)
	{
		ft_printf("%c", c);
		c = 0;
		counter = 0;
	}
}

int	main(void)
{
	ft_printf("The server PID is: %d\n", getpid());
}
