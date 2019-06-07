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

#ifndef FT_LS_H
# define FT_LS_H

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
	char			*user_name;
	int				user_name_len;
	int				group_id;
	char			*group_name;
	int				group_name_len;
	int				file_size;
	int				file_blocks;
	time_t			atime;
	time_t			mtime;
	time_t			ctime;
	char			*str_time;
	int				str_time_len;

	struct s_ls		*next;
}					t_ls;

short				g_flags;
/*
**flag 'a' - 0 bit;
**flag 'r' - 1 bit;
**flag 't' - 2 bit;
**flag 'l' - 3 bit;
**flag 'R' - 4 bit;
*/
unsigned long		g_list_size;
int					g_total_blocks;
int					g_max_group_len;
int					g_max_name_len;
int					g_max_link_len;
int					g_max_size_len;
int					g_max_time_flag;
t_ls				*create_elem(struct dirent *p_dir, char *path);
t_ls				*create_elem_file(char *path);
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
void				bust(char *path);
char				*calc_indents(t_ls *node);
void				get_u_g_name(t_ls *node);
void				get_min_name_len(t_ls *head);
char				*get_link_indents(void);
void				set_node_to_null(t_ls *node);
void				get_file_mode(t_ls *node);
void				get_time(t_ls *node);
void				file_mode_to_str(t_ls *node);
#endif
