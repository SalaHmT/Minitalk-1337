/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:58:44 by shamsate          #+#    #+#             */
/*   Updated: 2023/04/05 07:04:54 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void pass_char(pid_t pid, char c)
{
    int i;


    for(i = 7; i >= 0; i--)
    {

        if(c >> i & 1)
            kill(pid, SIGUSR2);

        else
            kill(pid, SIGUSR1);
    
        usleep(100);
    }
}

int main(int argc, char **argv)
{
    pid_t pid;
    char *str;

    
    if(argc != 3)
    {
        ft_putstr("Usage: ./client [server PID] [message] Diff In Prototype .. :/ - \n");
        return (1);
    }

    if(!ft_checkdigit_sign(argv[1]) || (pid = ft_atoi(argv[1])) <= 0)
    {
        ft_putstr("Invalid server -PID- . Please enter a positive integer.\n");
        return (1);
    }

    str = argv[2];
    while(*str)
    {
        pass_char(pid, *str);
        str++;
    }
    pass_char(pid, '\0');

    return (0);
}

