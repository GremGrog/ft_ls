/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:23:35 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/02 16:23:38 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	add_node_mtime(t_ls *head, t_ls *node)
{
	while (head->next != NULL)
	{
		if (head->next->file_name != NULL &&
			head->next->mtime < node->mtime)
		{
			node->next = head->next;
			head->next = node;
			return ;
		}
		head = head->next;
	}
	head->next = node;
	node->next = NULL;
}

void	add_node_reverse(t_ls *head, t_ls *node)
{
	while (head->next != NULL)
	{
		if (head->next->file_name != NULL &&
			ft_strcmp(head->next->file_name, node->file_name) < 0)
		{
			node->next = head->next;
			head->next = node;
			return ;
		}
		head = head->next;
	}
	head->next = node;
	node->next = NULL;
}

void	add_node_defolt(t_ls *head, t_ls *node)
{
	if (CHECK_BIT(g_flags, 1))
		return (add_node_reverse(head, node));
	if (CHECK_BIT(g_flags, 2))
		return (add_node_mtime(head, node));
	while (head->next != NULL)
	{
		if (head->next->file_name != NULL &&
			ft_strcmp(head->next->file_name, node->file_name) > 0)
		{
			node->next = head->next;
			head->next = node;
			return ;
		}
		head = head->next;
	}
	head->next = node;
	node->next = NULL;
}
