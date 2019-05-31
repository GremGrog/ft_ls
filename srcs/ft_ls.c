/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.21-school.ru>   +#+  +:+       +#+        */
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
		if (!CHECK_BIT(g_flags, 0))
		{
			while (p_dir != NULL && p_dir->d_name[0] == '.')
				p_dir = readdir(ptr);
		}
		if ((g = create_elem(p_dir, path)) == NULL)
			break ;
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
		ft_printf("%s\n",temp->file_name);
		temp = temp->next;
	}
}

t_ls		*create_list(char *path)
{
	t_ls			*head;
	int				i;

	i = 0;
	head = create_elem(NULL, NULL);
	if ((head = read_dir(path, head)) == NULL)
		return (NULL);
	head = head->next;
	if (head->file_name != NULL)
		output(head);
	if (CHECK_BIT(g_flags, 4))
		recursive_output(head);
	return (head);
}

void		ft_ls(char **argv, int argc)
{
	int		f;
	t_ls	*head;

	if (argc > 1)
	{
		f = add_flags(argv[1]);
		if (f == 0)
		{
			write(1, "illegal", 7);
			return ;
		}
		if (f == -1)
			head = create_list(argv[1]);
		if (f == 1 && argc == 2)
			head = create_list(".");
		if (argc == 3 && f == 1)
			head = create_list(argv[2]);
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
