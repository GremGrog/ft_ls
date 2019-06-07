/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_more_indents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:40:29 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/07 14:40:30 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*get_size_indents(void)
{
	char	*buf;
	char	*str;

	g_max_size_len = num_len(g_max_size_len);
	str = ft_itoa(g_max_size_len);
	buf = ft_strjoin(str, "d %s %s");
	free(str);
	return (buf);
}

char	*get_group_indents(void)
{
	char	*buf;
	char	*str;
	char	*tmp;

	g_max_group_len += 2;
	str = ft_itoa(g_max_group_len);
	buf = ft_strjoin(str, "s%");
	free(str);
	tmp = get_size_indents();
	str = ft_strjoin(buf, tmp);
	free(buf);
	free(tmp);
	return (str);
}

char	*get_name_indents(void)
{
	char	*buf;
	char	*str;
	char	*tmp;

	g_max_name_len += 2;
	str = ft_itoa(g_max_name_len);
	buf = ft_strjoin(str, "s%-");
	free(str);
	tmp = get_group_indents();
	str = ft_strjoin(buf, tmp);
	free(tmp);
	free(buf);
	return (str);
}

char	*get_link_indents(void)
{
	char	*buf;
	char	*tmp;
	char	*str;

	g_max_link_len = num_len(g_max_link_len) + 2;
	tmp = ft_itoa(g_max_link_len);
	buf = ft_strjoin(tmp, "d %-");
	free(tmp);
	str = get_name_indents();
	tmp = ft_strjoin(buf, str);
	free(buf);
	free(str);
	return (tmp);
}
