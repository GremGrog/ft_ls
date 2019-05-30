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
# include "ft_printf/MainHeader/ft_printf.h"

typedef struct	s_ls
{
	char		*file_name;
	itn			name_length;
	char		file_type;
	char		*path;
	struct s_ls	*next;
}				t_ls;

short			g_flags;
unsigned long	g_list_size;
t_ls			*create_elem(struct dirent *pDir, char *path);
void			add_node_to_end(t_ls *head, t_ls *node);
int				add_flags(char *argv);

#endif
