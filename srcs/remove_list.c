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

void		delete_elem(t_ls *head)
{
	if (head->file_name)
		free(head->file_name);
	if (head->path)
		free(head->path);
	if (head->full_path)
		free(head->full_path);
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
