/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:03:34 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/26 20:42:10 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void demarri()
{
    t_pipeline **long_str;
    char *line;
    while(1)
    {
        line = readline("Minishell $>: ");
        if (*line == '\0')
        {
            ft_putstr("Enter A Command\n");
            continue;
        }
        add_history(line);
        long_str = parse_info(line);
    }
}

int main(int ac, char **av, char **env)
{
    if (ac == 1)
        demarri();
    else
        ft_putstr("Usage: ./Minshell");
}