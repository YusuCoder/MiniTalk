/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:30:24 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/19 12:28:13 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			printf("Error! Please retype the PID!\n");
			return (1);
		}
		while (argv[2][i])
		{
			sig_handler(pid, argv[2][i]);
			i++;
		}
	}
	return (0);
}
