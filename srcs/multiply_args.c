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

int		create_elem_args(char *argv, t_ls *args)
{
	DIR				*ptr;
	t_ls			*node;

	if ((ptr = opendir(argv)) == NULL)
		return (-1);
	closedir(ptr);
	node = (t_ls*)malloc(sizeof(t_ls));
	node->file_name = (char*)malloc(sizeof(char) * ft_strlen(argv) + 1);
	ft_strcpy(node->file_name, argv);
	node->file_type = 'd';
	add_node_defolt(args, node);
	return (1);
}

void	print_multiply_args(t_ls *head)
{
	t_ls	*tmp;

	while (head != NULL)
	{
		ft_printf("%s:\n", head->file_name);
		create_list(head->file_name);
		if (head->next != NULL && head->file_type == 'd')
			ft_printf("\n");
		tmp = head;
		head = head->next;
		free(tmp->file_name);
		free(tmp);
	}
	free(head);
}

void	print_multiply_files(t_ls *head)
{
	t_ls	*files;

	files = head;
	output(files);
	remove_list(files);
	ft_printf("\n");
}

void	multiply_args(char **argv)
{
	t_ls		*head;
	t_ls		*buf;
	struct stat	w;

	if (*argv == NULL)
		return (create_list("."));
	head = create_elem(NULL, NULL);
	buf = create_elem(NULL, NULL);
	while (*argv != '\0')
	{
		if (create_elem_args(*argv, head) == -1)
		{
			if ((lstat(*argv, &w) == -1))
				ft_printf("./ft_ls: %s: No such file or directory\n", *argv);
			else
				add_node_defolt(buf, create_elem_file(*argv));
		}
		argv++;
	}
	if (buf->next)
		print_multiply_files(buf->next);
	if (head->next)
		print_multiply_args(head->next);
	free(buf);
	free(head);
}
