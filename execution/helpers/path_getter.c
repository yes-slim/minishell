/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:27:00 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/14 19:31:17 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(char *str, char **path)
{
	char	*cmd;
	int		i;

	i = 0;
	while (path[i])
	{
		cmd = _strjoin(path[i], str);
		if (access(cmd, X_OK) == -1)
			i++;
		else
			return (cmd);
	}
	return (NULL);
}

char	*path_getter(t_cmds *init)
{
	char	*path;

	if (!init->str[0][0])
		ft_error_exec(2, init->str[0], -1);
	if (init->str[0][0] == '/')
	{
		if (access(init->str[0], X_OK) == -1)
			ft_error_exec(1, init->str[0], -1);
		else
			return (_strdup(init->str[0]));
	}
	if (init->str[0][0] == '.' && init->str[0][1] == '/')
	{
		if (access(init->str[0], X_OK) == -1)
			ft_error_exec(1, init->str[0], -1);
		else
			return (_strdup(init->str[0]));
	}
	path = get_path(init->str[0], g_var.data->paths);
	if (!path)
		ft_error_exec(2, init->str[0], -1);
	else
		return (path);
	return (NULL);
}
