/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:11:09 by shamsate          #+#    #+#             */
/*   Updated: 2023/04/05 07:39:03 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

int		ft_isdigit(int c);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putendl(char *s);
int		ft_checkdigit_sign(char *str);
#endif

