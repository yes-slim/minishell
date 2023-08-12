/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:02 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/12 20:08:04 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "includes/structs.h"

int	main(int ac, char *av[], char *env[])
{
	t_data	data;

	if (ac > 1 || av[1])
		ft_errors_buster(1, &data);
	if (!ft_env_var(&data, env, 1))
		return (0);
	data.color = 1;
	g_var.data = &data;
	g_var.sig = 1;
	g_var.hd_expansion = 1;
	g_var.data->std_in = dup(0);
	if (g_var.data->std_in == -1)
		ft_error_exec(7, NULL, 0);
	g_var.data->std_out = dup(1);
	if (g_var.data->std_out == -1)
		ft_error_exec(7, NULL, 0);
	ft_shell_starter(&data);
	return (1);
}
