/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpwcall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:35:17 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/07 09:35:19 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	get_u_g_name(t_ls *node)
{
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(node->user_id);
	gr = getgrgid(node->group_id);
	node->user_name_len = ft_strlen(pw->pw_name);
	node->group_name_len = ft_strlen(gr->gr_name);
	node->user_name = (char*)malloc(sizeof(char) * node->user_name_len + 1);
	node->group_name = (char*)malloc(sizeof(char) * node->group_name_len + 1);
	ft_strcpy(node->user_name, pw->pw_name);
	ft_strcpy(node->group_name, gr->gr_name);
}
