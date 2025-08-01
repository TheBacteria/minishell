/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:44:55 by ymassiou          #+#    #+#             */
/*   Updated: 2024/09/15 17:53:08 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	unlink_fil(t_shell *data)
{
	int		i;
	int		j;
	char	*files;
	char	*file;

	i = 0;
	j = 0;
	files = data->filcollect;
	file = NULL;
	if (files == NULL)
		return ;
	while (files[i])
	{
		j = 0;
		while (files[i] && files[i] == '.')
			i++;
		j = i;
		while (files[j] && files[j] != '.')
			j++;
		file = ft_substr_mz(files, i, j, data);
		unlink(file);
		while (files[i] && files[i] != '.')
			i++;
	}
}

void	clean(t_shell *data)
{
	rl_clear_history();
	close_fildes(data);
	if (data->using_hdc)
		unlink_fil(data);
	free_command(data);
	free_programm(data);
}

void	stop_programm(t_shell *data)
{
	clean(data);
	exit(MALLOC_FAILURE);
}

void	fds_error(t_shell *data, char *msg)
{
	putstr_fd(msg, 2);
	data->status = 1;
	close_fildes(data);
}

void	improved_exit(int val, t_shell *data)
{
	clean(data);
	exit(val);
}
