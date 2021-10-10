/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:36:37 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/10 19:32:46 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int     main(int ac, char **av, char **env)
{
	t_envs	*envs;

	envs = create_envs(env);
	print_env(envs);

}