/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:39:02 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 10:29:55 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_lexer	*lexer;

	(void)av;
	init_envs(env);
	refresh_bash();
	if (ac == 1)
	{
		while (TRUE)
		{
			catch_the_signal();
			g_exe.line = readline("BASH$>: ");
			if (!g_exe.line)
			{
				ft_putstr_fd("exit\n", 1);
				return (0);
			}
			if (g_exe.line[0] == '\0')
				continue ;
			add_history(g_exe.line);
			lexer = init_lexer(g_exe.line);
			parse(lexer);
			if (g_exe.cmd && g_exe.lexer_err == 0)
				execute_pipe(g_exe.cmd);
			free(lexer);
			refresh_bash();
		}
	}
	return (0);
}