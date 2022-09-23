/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:53:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/23 21:44:12 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	built_in_cmd(char *cmd)
{
	if ((ft_str_is_equal(cmd, "echo")
		|| ft_str_is_equal(cmd, "cd"))
		|| ft_str_is_equal(cmd, "pwd")
		|| ft_str_is_equal(cmd, "unset")
		|| ft_str_is_equal(cmd, "export")
		|| ft_str_is_equal(cmd, "exit")
		|| ft_str_is_equal(cmd, "env"))
		return (1);
	return (0);
}

void	is_built_in(t_table **tab, t_exec *exec)
{
	if (ft_str_is_equal((*tab)->cmd_line[0], "echo"))
		echo(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
		cd(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "pwd"))
		pwd(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "unset"))
		unset(tab, exec);
	if (exec->amount_cmd == 1 && built_in_cmd((*tab)->cmd_line[0]))
	{
		exec->amount_cmd--;
		exec->exit = 0;
	}
}
