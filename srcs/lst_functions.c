/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:58:33 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/27 17:08:46 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_ls		*get_path(t_ls *node, char *path)
{
	char	*buf;

	
}

t_ls		*create_elem(struct dirent *pDir, char *path)
{
	t_ls	*node;

	node = (t_ls*)malloc(sizeof(t_ls));
	node->file_type = 0;
	if (pDir)
	{
		node->name_length = ft_strlen(pDir->d_name);
		if (!(node->file_name = malloc(sizeof(char) * node->name_length + 1)))
				return (NULL);
		ft_strcpy(node->file_name, pDir->d_name);
		node->file_type = pDir->d_type;
		get_path(node, path);
	}
	else
		node->file_name = NULL;
	node->next = NULL;
	return (node);
}

void		add_node_to_end(t_ls *head, t_ls *node)
{
	while (head->next != NULL)
		head = head->next;
	head->next = node;
	node->next = NULL;
}
