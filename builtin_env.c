/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:53:59 by hcolumbu          #+#    #+#             */
/*   Updated: 2022/06/17 13:51:23 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_envp *envp_list)
{
	if (!envp_list)
		return (1);
	if (var_position_in_envp(envp_list, "PATH") == -1)
	{
		ft_putendl_fd("Myshell 🐚: env: No such file or directory", 2);
		return (127);
	}
	while (envp_list)
	{
		ft_putstr_fd(envp_list->key, 1);
		ft_putchar_fd('=', 1);
		ft_putendl_fd(envp_list->value, 1);
		envp_list = envp_list->next;
	}
	return (0);
}
