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
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "ft_printf/MainHeader/ft_printf.h"

typedef struct		s_ls
{
	char			*file_name;
	int				name_length;
	char			*path;
	int				path_length;
	char			*full_path;
	unsigned char	file_type;
	mode_t			file_mode;
	char			*str_mode;
	nlink_t			file_links;
	int				user_id;
	int				group_id;
	int				file_size;
	int				file_blocks;
	time_t			atime;
	time_t			mtime;
	time_t			ctime;
	char			*str_time;

	struct s_ls		*next;
}					t_ls;

typedef struct		s_args
{
	char			*arg_name;
	struct s_args	*next;
}					t_args;

short				g_flags;
/*
flag 'a' - 0 bit;
flag 'r' - 1 bit;
flag 't' - 2 bit;
flag 'l' - 3 bit;
flag 'R' - 4 bit;
*/
unsigned long		g_list_size;
int					g_total_blocks;
t_ls				*create_elem(struct dirent *pDir, char *path);
void				add_node_defolt(t_ls *head, t_ls *node);
int					add_flags(char *argv);
int					read_dir(char *path, t_ls *head);
void				create_list(char *path);
void				recursive_output(char *path);
void				output(t_ls *head);
void				delete_elem(t_ls *head);
void				remove_list(t_ls *head);
void				lstat_call(t_ls *node);
void				long_format_output(t_ls *node);
void				multiply_args(char **argv);
#endif
