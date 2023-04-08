/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:04:15 by shamsate          #+#    #+#             */
/*   Updated: 2023/04/08 01:04:17 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	pass_char(pid_t pid, char c)
{
	int	i;

	i = 8;
	while ((--i) >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
}

void	recive_sig(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("Received successfully :)");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
	{
		ft_putstr("Diff: ./client [server PID] [message] Prototype .. :/ \n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!ft_checkdigit_sign(argv[1]) || (pid <= 0))
	{
		ft_putstr("Invalid server -PID- . Please enter Valid PID .\n");
		return (1);
	}
	signal(SIGUSR1, recive_sig);
	str = argv[2];
	while (*str)
	{
		pass_char(pid, *str);
		str++;
	}
	pass_char(pid, '\0');
	return (0);
}
