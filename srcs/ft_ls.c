/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:58:29 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/29 18:23:15 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_ls		*read_dir(char *path)
{
	DIR				*ptr;
	struct dirent	*pDir;
	t_ls			*g;
	t_ls			*head;
	char			*dir_name;

	pDir = NULL;
	g = create_elem(pDir, "0");
	head = g;
	ptr = opendir(path);
	if (ptr == NULL)
		return (NULL);
	dir_name = malloc(sizeof(char) * ft_strlen(path) + 1);
	ft_strcpy(dir_name, path);
	while ((pDir = readdir(ptr)) != NULL)
	{
		g = create_elem(pDir, path);
		add_node_to_end(head, g);
		g = g->next;
		g_list_size++;
	}
	closedir (ptr);
	head = head->next;
	while (head != NULL)
	{
		ft_printf("%s %s\n",head->path, head->file_name);
		head = head->next;
	}
	return (head);
}

void		ft_ls(char **argv, int argc)
{
	int		f;

	if (argc > 1)
	{
		f = add_flags(argv[1]);
		if (f == 0)
		{
			write(1, "illegal", 7);
			return ;
		}
		if (f == -1)
			read_dir(argv[1]);
		if (f == 1)
			read_dir(".");
	}
}

int	main(int argc, char **argv)
{
	g_list_size = 0;
	g_flags = 0;
	if (argc == 1)
		read_dir(".");
	if (argc == 2 || argc == 3)
		ft_ls(argv, argc);
}
