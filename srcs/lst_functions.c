/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:24:09 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/02 20:24:11 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_ls				*add_path(t_ls *node, char *buf)
{
	char	*tmp;

	node->path = (char*)malloc(sizeof(char) * node->path_length + 1);
	node->path = ft_strcpy(node->path, buf);
	node->full_path = (char*)malloc(sizeof(char) *
		(node->path_length + node->name_length) + 1);
	tmp = ft_strjoin(node->path, node->file_name);
	node->full_path = ft_strcpy(node->full_path, tmp);
	free(buf);
	free(tmp);
	return (node);
}

t_ls				*get_path(t_ls *node, char *path)
{
	char	*buf;
	char	*tmp;

	if (path[0] == '.' && path[1] == '\0')
	{
		buf = (char*)malloc(sizeof(char) * (3 + node->name_length));
		ft_strcpy(buf, "./");
		node->path_length = 2;
	}
	else
	{
		node->path_length = ft_strlen(path);
		buf = (char*)malloc(sizeof(char) * node->path_length + 2);
		buf = ft_strcpy(buf, path);
		tmp = ft_strjoin(buf, "/");
		buf = ft_strcpy(buf, tmp);
		free(tmp);
		node->path_length += 1;
	}
	return (add_path(node, buf));
}

unsigned char		get_file_type(struct dirent *p_dir, unsigned char file_type)
{
	if (p_dir->d_type == DT_BLK)
		file_type = 'b';
	if (p_dir->d_type == DT_CHR)
		file_type = 'c';
	if (p_dir->d_type == DT_DIR)
		file_type = 'd';
	if (p_dir->d_type == DT_FIFO)
		file_type = 'p';
	if (p_dir->d_type == DT_LNK)
		file_type = 'l';
	if (p_dir->d_type == DT_REG)
		file_type = '-';
	if (p_dir->d_type == DT_SOCK)
		file_type = 's';
	return (file_type);
}

t_ls				*create_elem(struct dirent *p_dir, char *path)
{
	t_ls	*node;

	node = (t_ls*)malloc(sizeof(t_ls));
	node->file_type = 0;
	node->str_mode = NULL;
	node->str_time = NULL;
	if (p_dir)
	{
		node->name_length = ft_strlen(p_dir->d_name);
		if (!(node->file_name = malloc(sizeof(char) * node->name_length + 1)))
			return (NULL);
		ft_strcpy(node->file_name, p_dir->d_name);
		node->file_type = get_file_type(p_dir, node->file_type);
		get_path(node, path);
		if (CHECK_BIT(g_flags, 3) || CHECK_BIT(g_flags, 2))
			lstat_call(node);
	}
	else
	{
		node->file_name = NULL;
		node->full_path = NULL;
		node->path = NULL;
	}
	node->next = NULL;
	return (node);
}
