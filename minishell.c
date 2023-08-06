/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:02 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/05 12:53:07 by YOUNES           ###   ########.fr       */
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
	ft_shell_starter(&data);
	return (1);
}
