/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:00:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/26 17:52:58 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clean_exit(char *free_me)
{
	free(free_me);
	ft_free_array(global()->envp);
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	exit (global()->exit);
}
