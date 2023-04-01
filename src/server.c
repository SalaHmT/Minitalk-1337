/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:58:50 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/29 21:58:54 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static	void server_get(int sig, siginfo_t *sig_info, void *str)
{
	static	int		i;
	static	int		C_pid;
	static	char	c;

	if(C_pid != sig_info->si_pid)
	{
		i = 0;
		c = 0;
		C_pid = sig_info->si_pid;
	}
	i++;
	c = c << 1 | (sig - SIGUSR1);
	if (i == 8)
	{
		ft_putchar(c);
		c = 0;
		i = 0;
	}
}

int main ()
{
	int pid;
	struct sigaction	S_usr;

	pid = (int)getpid();
	ft_putstr(" Your - PID - :\t");
	ft_putnbr(pid);
	ft_putchar('\n');
	S_usr.sa_flags = SA_SIGINFO;
	S_usr.sa_sigaction = server_get;
	sigaction(SIGUSR1, &S_usr, NULL);
	sigaction(SIGUSR2, &S_usr, NULL);
	while(1)
		pause();
	return (0);
}
