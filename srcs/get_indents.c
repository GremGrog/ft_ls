/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indents.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:56:21 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/07 10:56:22 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*get_indents(void)
{
	char	*buf;
	char	*tmp;

	buf = get_link_indents();
	tmp = ft_strjoin("%s%", buf);
	free(buf);
	return (tmp);
}

char	*calc_indents(t_ls *node)
{
	t_ls	*temp;

	temp = node;
	g_max_link_len = temp->file_links;
	g_max_size_len = temp->file_size;
	g_max_group_len = temp->group_name_len;
	g_max_name_len = temp->user_name_len;
	while ((temp = temp->next) != NULL)
	{
		if (g_max_link_len < temp->file_links)
			g_max_link_len = temp->file_links;
		if (g_max_size_len < temp->file_size)
			g_max_size_len = temp->file_size;
		if (g_max_name_len < temp->user_name_len)
			g_max_name_len = temp->user_name_len;
		if (g_max_group_len < temp->group_name_len)
			g_max_group_len = temp->group_name_len;
	}
	free(temp);
	return (get_indents());
}
