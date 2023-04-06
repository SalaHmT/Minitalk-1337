/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.dependency.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:12:03 by shamsate          #+#    #+#             */
/*   Updated: 2023/04/06 02:50:57 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putnbr(int n)
{
	long int	n2;

	n2 = n;
	if (n2 < 0)
	{
		n2 = (n2 * -1);
		write(1, "-", 1);
	}
	if (n2 > 9)
	{
		ft_putnbr(n2 / 10);
		ft_putchar((n2 % 10) + '0');
	}
	else
		ft_putchar(n2 + '0');
}

void	ft_putendl(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
