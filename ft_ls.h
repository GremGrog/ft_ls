/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:50:15 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/28 21:22:51 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <time.h>
# include "ft_printf/MainHeader/ft_printf.h"

typedef struct	s_ls
{
	char			*file_name;
	int				name_length;
	char			*path;
	int				path_length;
	char			*full_path;
	unsigned char	file_type;
	mode_t			file_mode;
	nlink_t			file_links;
	uid_t			user_name;
	gid_t			group_name;
	off_t			file_size;
	blksize_t		file_blocks;
	time_t			atime;
	time_t			mtime;
	time_t			ctime;

	struct s_ls		*next;
}				t_ls;

short			g_flags;
unsigned long	g_list_size;
t_ls			*create_elem(struct dirent *pDir, char *path);
void			add_node_defolt(t_ls *head, t_ls *node);
int				add_flags(char *argv);
void			read_dir(char *path, t_ls *head);
void			create_list(char *path);
void			recursive_output(char *path);
void			output(t_ls *head);
void			delete_elem(t_ls *head);
void			remove_list(t_ls *head);
void			lstat_call(t_ls *node);
#endif
