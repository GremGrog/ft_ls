/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 14:40:41 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/01 14:40:44 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		set_node_to_null(t_ls *node)
{
	node->file_type = 0;
	node->str_mode = NULL;
	node->str_time = NULL;
	node->user_name = NULL;
	node->group_name = NULL;
	node->str_time = NULL;
	node->file_name = NULL;
	node->full_path = NULL;
	node->path = NULL;
}

void		delete_elem(t_ls *head)
{
	if (head->file_name)
		free(head->file_name);
	if (head->path)
		free(head->path);
	if (head->full_path)
		free(head->full_path);
	if (head->str_mode)
		free(head->str_mode);
	if (head->str_time)
		free(head->str_time);
	if (head->user_name)
		free(head->user_name);
	if (head->group_name)
		free(head->group_name);
	free(head);
}

void		remove_list(t_ls *head)
{
	t_ls	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		delete_elem(tmp);
	}
}
