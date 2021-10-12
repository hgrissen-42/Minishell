/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:46:05 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/11 14:38:54 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
#define EXECUTION_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef		struct	s_envs
{
	char			*full;
	char			*bef_eq;
	char			*aft_eq;
	struct	s_envs	*next;
	struct	s_envs	*prev;
}					t_envs;

char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
int			ft_strlen(char *s);
char		**ft_split(char *s, char c);
int			ft_strcmp(char *s1, char *s2);

// envs
t_envs		*create_envs(char **env);
void		print_env(t_envs	*envs);
void		print_export(t_envs *envs);

#endif