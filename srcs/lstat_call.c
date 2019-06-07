/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstat_call.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:21:49 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/07 15:21:51 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	lstat_call(t_ls *node)
{
	struct stat		buf;

	if (node->file_name == NULL)
		return ;
	lstat(node->full_path, &buf);
	node->file_mode = buf.st_mode;
	node->file_links = buf.st_nlink;
	node->user_id = buf.st_uid;
	node->group_id = buf.st_gid;
	node->file_size = buf.st_size;
	node->file_blocks = buf.st_blocks;
	node->atime = buf.st_atime;
	node->mtime = buf.st_mtime;
	node->ctime = buf.st_ctime;
	g_total_blocks += buf.st_blocks;
	if (node->file_type == 0)
		get_file_mode(node);
	if (CHECK_BIT(g_flags, 3))
	{
		file_mode_to_str(node);
		get_time(node);
		get_u_g_name(node);
	}
}
