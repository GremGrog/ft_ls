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

void	recursive_output(t_ls *head)
{
	t_ls	*temp;
	t_ls	*buf;

	ft_printf("\n");
	if (head->file_name == NULL || head->file_type == 'f' )
		return ;
	temp = head;
	while (temp->next)
	{
		if (temp->file_type == 'd')
		{
			ft_printf("TP%s:\n", temp->full_path);
			buf = create_list(temp->full_path);
			temp = temp->next;
			if (buf->next != NULL)
				buf = buf->next;
			if (buf->file_type == 'd')
				ft_printf("BF%s:\n", buf->full_path);
			buf = create_list(buf->full_path);
			if (temp->file_name == NULL || temp->file_type == 'f')
				return ;
		}
		else
			temp = temp->next;
	}
}
