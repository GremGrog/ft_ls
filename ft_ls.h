/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:50:15 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/27 17:08:17 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h> //!!!!!!!!!!!!!!!!!!!!!!
# define CHECK_BIT(var, position) (var &(1 << position)) ? 1 : 0
# define PUT_BIT(var, position) (var |= (1 << position))
# define DEL_BIT(var, position) (var &= ~(1 << position))

typedef struct	s_ls
{
	char		*file_name;
	char		file_type;
	struct s_ls	*next;
}				t_ls;

short			g_flags;
unsigned long	g_list_size;
t_ls			*create_elem(struct dirent *pDir);
void			add_node_to_end(t_ls *head, t_ls *node);
int				add_flags(char *argv);

#endif
