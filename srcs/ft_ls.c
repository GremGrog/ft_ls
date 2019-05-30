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

t_ls		*read_dir(char *path, t_ls *head)
{
	DIR				*ptr;
	struct dirent	*p_dir;
	t_ls			*g;

	ptr = opendir(path);
	if (ptr == NULL)
		return (NULL);
	while ((p_dir = readdir(ptr)) != NULL)
	{
		g = create_elem(p_dir, path);
		add_node_defolt(head, g);
		g = g->next;
		g_list_size++;
	}
	closedir (ptr);
	return (head);
}

void		output(t_ls *head)
{
	t_ls	*temp;

	if (!head)
		return ;
	temp = head;
	while (temp != NULL)
	{
		if (!CHECK_BIT(g_flags, 0))
		{
			while (temp && temp->file_name[0] == '.')
				temp = temp->next;
			if (temp == NULL)
				break ;
		}
		ft_printf("%s\n",temp->file_name);
		temp = temp->next;
	}
}

void		create_list(char *path)
{
	t_ls			*head;
	int				i;

	i = 0;
	head = create_elem(NULL, NULL);
	if ((head = read_dir(path, head)) == NULL)
		return ;
	head = head->next;
	output(head);
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
			create_list(argv[1]);
		if (f == 1)
			create_list(".");
	}
}

int	main(int argc, char **argv)
{
	g_list_size = 0;
	g_flags = 0;
	if (argc == 1)
		create_list(".");
	else
		ft_ls(argv, argc);
}
