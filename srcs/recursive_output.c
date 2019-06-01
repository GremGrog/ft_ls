/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:58:53 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/31 13:58:56 by fmasha-h         ###   ########.fr       */
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
				ft_printf("FP%s:\n", temp->full_path);
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

	head = create_elem(NULL, NULL);
	read_dir(path, head);
	temp = head->next;
	if (temp->file_name != NULL)
		output(temp);
	ft_printf("\n");
	temp = recursive_loop(temp);
	remove_list(temp);
	free(head);
}
