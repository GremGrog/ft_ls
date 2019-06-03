/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:23:59 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/02 20:24:01 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_ls	*recursive_loop(t_ls *temp)
{
	t_ls	*buf;

	while (temp != NULL)
	{
		if (temp->file_type == 'd')
		{
			if ((temp->file_name[0] == '.' && temp->file_name[1] == '.') ||
				(temp->file_name[0] == '.' && temp->name_length == 1))
			{
				buf = temp;
				temp = temp->next;
				delete_elem(buf);
			}
			else
			{
				ft_printf("%s:\n", temp->full_path);
				recursive_output(temp->full_path);
			}
		}
		buf = temp;
		temp = temp->next;
		delete_elem(buf);
	}
	return (temp);
}

void	recursive_output(char *path)
{
	t_ls	*head;
	t_ls	*temp;

	g_total_blocks = 0;
	head = create_elem(NULL, NULL);
	if (read_dir(path, head) == -1)
	{
		ft_printf("./ft_ls: %s: No such file or directory\n", path);
		exit(-1);
	}
	temp = head->next;
	if (temp->file_name != NULL)
	{
		if (CHECK_BIT(g_flags, 3))
			long_format_output(temp);
		else
			output(temp);
	}
	ft_printf("\n");
	temp = recursive_loop(temp);
	remove_list(temp);
	free(head);
}
