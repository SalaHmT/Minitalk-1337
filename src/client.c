/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:58:44 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/29 21:58:45 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static	void	pass_char(pid_t pid, char str)
{
	int	i;

	i = 8;
	while((--i) >= 0)
	{
		if(str & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid,SIGUSR1);
		usleep(500);
	}
}

int main (int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc == 3)
	{
		if(ft_checkdigit_sign(argv[1] == 1))
		{
			pid =(pid_t)ft_atoi(argv[1]);
			if (pid > 0)
			{
				str = argv[2];
				while(*str)
				{
					pass_char(pid,*str);
					str++;
				}
			}
			else
				ft_putstr("- The PID Server Is Not Valid. :/ -  ");
		}
		else
			ft_putstr(" - Error In - PID - Must Contain Only Number. :/ - ");
	}
	else
		ft_putstr(" - Something Wrong - Dif In Input - :/ - ");
		return (0);
}
