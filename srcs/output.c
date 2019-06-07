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

void	long_format_output(t_ls *node)
{
	t_ls			*temp;
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
		ft_printf(ft_printf_str,
		temp->str_mode, temp->file_links, temp->user_name, temp->group_name,
		temp->file_size, temp->str_time, temp->file_name);
		if (temp->file_type == 'l')
			print_link(temp);
		ft_printf("\n");
		temp = temp->next;
	}
	free(ft_printf_str);
}
