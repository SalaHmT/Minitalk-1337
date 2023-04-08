/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:20:26 by shamsate          #+#    #+#             */
/*   Updated: 2023/04/08 01:20:28 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	server_get(int sig, siginfo_t *sig_info, void *str)
{
	static int			c_pid = 0;
	static int			i = 0;
	static char			c = 0;

	(void)str;
	if (c_pid != sig_info->si_pid)
	{
		c_pid = sig_info->si_pid;
	}
	c |= (sig == SIGUSR2);
	if ((++i) == 8)
	{
		if (c == '\0')
			kill(sig_info->si_pid, SIGUSR1);
		ft_putchar(c);
		c = 0;
		i = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putendl("Server PID:");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = server_get;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
