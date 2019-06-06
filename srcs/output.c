/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:21:00 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/02 20:21:03 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	output(t_ls *head)
{
	t_ls	*temp;

	if (!head)
		return ;
	if (CHECK_BIT(g_flags, 3))
		return (long_format_output(head));
	temp = head;
	while (temp != NULL)
	{
		ft_printf("%s\n", temp->file_name);
		temp = temp->next;
	}
}

void	print_link(t_ls *temp)
{
	char	*buf;

	buf = (char*)malloc(sizeof(char) * temp->file_size + 1);
	ft_bzero(buf, temp->file_size + 1);
	readlink(temp->full_path, buf, temp->file_size);
	ft_printf(" -> %s", buf);
	free(buf);
}

char	*get_indents(int l, int s)
{
	char	*link_indents;
	char	*size_indents;
	char	*buf;
	char	*str;

	link_indents = ft_itoa(l);
	size_indents = ft_itoa(s);
	buf = ft_strjoin("%s%", link_indents);
	free(link_indents);
	link_indents = ft_strjoin(buf, "d %s%6s%");
	free(buf);
	buf = ft_strjoin(link_indents, size_indents);
	free(link_indents);
	free(size_indents);
	size_indents = ft_strjoin(buf, "d %s %s");
	free(buf);
	str = (char*)malloc(sizeof(char) * 50);
	ft_strcpy(str, size_indents);
	free(size_indents);
	return (str);
}

char	*calc_indents(t_ls *node)
{
	t_ls	*temp;
	t_ls	*buf;
	int		max_link_len;
	int		max_size_len;

	temp = node;
	buf = node;
	max_link_len = temp->file_links;
	while ((temp = temp->next) != NULL)
	{
		if (max_link_len < temp->file_links)
			max_link_len = temp->file_links;
	}
	free(temp);
	max_size_len = buf->file_size;
	while (buf != NULL)
	{
		if (max_size_len < buf->file_size)
			max_size_len = buf->file_size;
		buf = buf->next;
	}
	max_link_len = num_len(max_link_len) + 2;
	max_size_len = num_len(max_size_len) + 2;
	free(buf);
	return (get_indents(max_link_len, max_size_len));
}

void	long_format_output(t_ls *node)
{
	t_ls			*temp;
	struct passwd	*pw_d;
	struct group	*gr_d;
	char			*ft_printf_str;

	if (!node)
		return ;
	temp = node;
	ft_printf_str = calc_indents(node);
	if (!((temp->file_type == '-' || temp->file_type == 'l')
	&& g_list_size == 0))
		ft_printf("total %d\n", g_total_blocks);
	while (temp != NULL)
	{
		pw_d = getpwuid(temp->user_id);
		gr_d = getgrgid(temp->group_id);
		ft_printf(ft_printf_str,
		temp->str_mode, temp->file_links, pw_d->pw_name, gr_d->gr_name,
		temp->file_size, temp->str_time, temp->file_name);
		if (temp->file_type == 'l')
			print_link(temp);
		ft_printf("\n");
		temp = temp->next;
	}
	free(ft_printf_str);
}
