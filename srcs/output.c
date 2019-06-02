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

void	long_format_output(t_ls *node)
{
	t_ls			*temp;
	struct passwd	*pw_d;
	struct group	*gr_d;

	if (!node)
		return ;
	temp = node;
	ft_printf("total %d\n", g_total_blocks);
	while (temp != NULL)
	{
		pw_d = getpwuid(temp->user_id);
		gr_d = getgrgid(temp->group_id);
		ft_printf("%s%3d %s%6s%7d %s %s",
		temp->str_mode, temp->file_links, pw_d->pw_name, gr_d->gr_name,
		temp->file_size, temp->str_time, temp->file_name);
		if (temp->file_type == 'l')
			print_link(temp);
		ft_printf("\n");
		temp = temp->next;
	}
}
