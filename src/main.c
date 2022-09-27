/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:11:39 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/27 12:13:11 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_new_tab(t_table *tab)
{
	tab->cmd = ft_strdup("");
	tab->cmd_line = ft_create_blank_array();
	tab->path = ft_create_blank_array();
	tab->envp = NULL;
	tab->envp = ft_create_blank_array();
	tab->next = NULL;
	tab->in_file = ft_strdup("");
	tab->out_file = ft_strdup("");
}

void	hard_init(char **envp)
{
	global()->test = 0;
	global()->heredoc = 0;
	global()->exit = 0;
	global()->envp = ft_array_dup(envp);
	global()->tabble = malloc(sizeof(t_table));
	init_new_tab(global()->tabble);
}

t_test	*global(void)
{
	static t_test	test;

	return (&test);
}

int	main(int argc, char **argv, char **envp)
{
	if (argv && argc > 1)
	{
		ft_putstr_fd("Error. No arguments are necessary", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	hard_init(envp);
	minishell(&global()->tabble);
	return (global()->exit);
}
