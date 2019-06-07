/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:35:06 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/01 20:35:11 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	mode_to_str_loop(int i, int f, t_ls *node)
{
	int	c;
	int	d;

	d = 0;
	c = 0;
	while (node != NULL && c < 3 && i > 0)
	{
		d = f % 8;
		if (CHECK_BIT(d, 0) == 1)
			node->str_mode[i--] = 'x';
		else
			node->str_mode[i--] = '-';
		if (CHECK_BIT(d, 1) == 1)
			node->str_mode[i--] = 'w';
		else
			node->str_mode[i--] = '-';
		if (CHECK_BIT(d, 2) == 1)
			node->str_mode[i--] = 'r';
		else
			node->str_mode[i--] = '-';
		f /= 8;
		c++;
	}
	node->str_mode[10] = '\0';
}

void	file_mode_to_str(t_ls *node)
{
	int	i;
	int f;

	i = 0;
	f = node->file_mode;
	node->str_mode = (char*)malloc(sizeof(char) * 11);
	ft_bzero(node->str_mode, 10);
	if (!node->str_mode)
		return ;
	node->str_mode[0] = node->file_type;
	i = 9;
	mode_to_str_loop(i, f, node);
}

void	copy_year(t_ls *node, int i, int j, char *time)
{
	while (i < 11)
		node->str_time[j++] = time[i++];
	while (i < 19)
		i++;
	while (i < 24)
		node->str_time[j++] = time[i++];
	node->str_time[j] = '\0';
	node->str_time_len = j;
}

void	get_time(t_ls *node)
{
	char	*time;
	int		i;
	int		j;

	i = 0;
	j = 0;
	node->str_time = (char*)malloc(sizeof(char) * 13);
	time = ctime(&node->ctime);
	while (i <= 3)
		i++;
	if (time[23] == '9')
	{
		while (i < 16)
			node->str_time[j++] = time[i++];
		node->str_time[j] = '\0';
		node->str_time_len = j;
		node->str_time[j] = '\0';
		node->str_time_len = j;
	}
	else
		copy_year(node, i, j, time);
}

void	get_file_mode(t_ls *node)
{
	if (S_ISREG(node->file_mode))
		node->file_type = '-';
	if (S_ISDIR(node->file_mode))
		node->file_type = 'd';
	if (S_ISCHR(node->file_mode))
		node->file_type = 'c';
	if (S_ISBLK(node->file_mode))
		node->file_type = 'b';
	if (S_ISFIFO(node->file_mode))
		node->file_type = 'p';
	if (S_ISLNK(node->file_mode))
		node->file_type = 'l';
}
