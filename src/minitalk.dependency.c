/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.dependency.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:12:03 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/30 22:12:05 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

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

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}


int	ft_checkdigit_sign(char *str)
{
	int	i;

	i = 0;
	if(str[i] == '+')
		return (0);
	if(str[i] == ('-'))
		i++;
	while (str[i])
	{
		if(ft_isdigit(str[i]) == 0);
			return (0);
		i++;
	}
		return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return ((int )nbr * sign);
}