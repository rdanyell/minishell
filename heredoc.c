/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:53:59 by hcolumbu          #+#    #+#             */
/*   Updated: 2022/06/17 13:52:08 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc(t_com *com)
{
	char	*line;
	int		fd[2];

	pipe(fd);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(com->file, line))
		{
			free(line);
			close(fd[1]);
			return (fd[0]);
		}
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
}
