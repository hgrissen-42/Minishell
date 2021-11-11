/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:42:08 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/11 10:20:55 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/builtins.h"

void	exit_builtin(t_cmd	*cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	if (i == 1)
		exit(g_exe.ret);
	else if (i == 2)
		exit(atoi(cmd->args[1]));
}
