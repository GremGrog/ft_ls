/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 21:04:12 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/02 21:04:15 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_args	*create_arg_node(char **argv)
{
	t_args	*node;
	DIR		*ptr;

	node = (t_args*)malloc(sizeof(t_args));
	if (argv)
	{
		if (*argv[0] != '-')
			ptr = opendir(*argv);
		else
			return (NULL);
		if (ptr == NULL)
		{
			ft_printf("./ft_ls: %s: No such file or directory\n", *argv);
			free(node);
			return (NULL);
		}
		closedir(ptr);
		node->arg_name = (char*)malloc(sizeof(char) * ft_strlen(*argv) + 1);
		ft_strcpy(node->arg_name, *argv);
	}
	node->next = NULL;
	return (node);
}

void	sort_args(t_args *head, t_args *node)
{
	if (!node)
		return ;
	while (head->next != NULL)
	{
		if (head->next->arg_name != NULL &&
			ft_strcmp(head->next->arg_name, node->arg_name) > 0)
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

void	delete_args_list(t_args *buf)
{
	t_args *tmp;

	while (buf != NULL)
	{
		if (buf->arg_name)
			free(buf->arg_name);
		tmp = buf;
		buf = buf->next;
		free(tmp);
	}
}

void	multiply_args(char **argv)
{
	t_args	*head;
	t_args	*tmp;
	t_args	*buf;
	int		i;

	head = create_arg_node(NULL);
	i = 1;
	while (argv[i] != '\0')
	{
		sort_args(head, create_arg_node(&argv[i]));
		i++;
	}
	tmp = head->next;
	buf = head->next;
	while (tmp != NULL)
	{
		ft_printf("%s:\n", tmp->arg_name);
		create_list(tmp->arg_name);
		if (tmp->next != NULL)
			ft_printf("\n");
		tmp = tmp->next;
	}
	delete_args_list(buf);
	free(head);
}
