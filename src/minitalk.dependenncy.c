#include "../include/minitalk.h"

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
		if(ft_isdigit(str[i]) == 0)
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

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

