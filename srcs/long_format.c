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

void	lstat_call(t_ls *node)
{
	struct stat		buf;

	if (node->file_name == NULL)
		return ;
	lstat(node->full_path, &buf);
	node->file_mode = buf.st_mode;
	node->file_links = buf.st_nlink;
	node->user_name = buf.st_uid;
	node->group_name = buf.st_gid;
	node->file_size = buf.st_size;
	node->file_blocks = buf.st_blocks;
	node->atime = buf.st_atime;
	node->mtime = buf.st_mtime;
	node->ctime = buf.st_ctime;
}
