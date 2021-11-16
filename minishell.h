/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:38:49 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 23:54:39 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <string.h>
# include <sys/wait.h>
# include  <sys/errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/errno.h>

# include "./incs/builtins.h"
# include "./incs/execution.h"
# include "./incs/parsing.h"

#endif