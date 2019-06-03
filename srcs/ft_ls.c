/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:23:45 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/02 20:23:48 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		read_dir(char *path, t_ls *head)
{
	DIR				*ptr;
	struct dirent	*p_dir;

	ptr = opendir(path);
	if (ptr == NULL)
		return (-1);
	while ((p_dir = readdir(ptr)) != NULL)
	{
		if (!CHECK_BIT(g_flags, 0))
		{
			while (p_dir != NULL && p_dir->d_name[0] == '.')
				p_dir = readdir(ptr);
		}
		add_node_defolt(head, create_elem(p_dir, path));
		g_list_size++;
	}
	closedir(ptr);
	return (1);
}

void	create_list(char *path)
{
	t_ls	*head;
	t_ls	*tmp;

	if (CHECK_BIT(g_flags, 4))
		return (recursive_output(path));
	g_total_blocks = 0;
	head = create_elem(NULL, NULL);
	if (read_dir(path, head) == -1)
	{
		ft_printf("./ft_ls: %s: No such file or directory\n", path);
		exit(-1);
	}
	tmp = head->next;
	if (tmp->file_name != NULL)
	{
		if (CHECK_BIT(g_flags, 3))
			long_format_output(tmp);
		else
			output(tmp);
	}
	remove_list(tmp);
	free(head);
}

void	ft_ls(char **argv, int argc)
{
	int		f;
	int		i;

	i = 1;
	f = 0;
	if (argc > 1)
	{
		while (argv[i])
		{
			f = add_flags(argv[i]);
			if (f == -1)
				break ;
			i++;
		}
		if (f == -1 && argc == 2)
			create_list(argv[i]);
		if (f == 1 && argc == 2)
			create_list(".");
		else
			multiply_args(&argv[i]);
	}
}

int		main(int argc, char **argv)
{
	g_list_size = 0;
	g_flags = 0;
	if (argc == 1)
		create_list(".");
	else
		ft_ls(argv, argc);
}
