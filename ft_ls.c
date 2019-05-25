/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:58:29 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/25 21:47:59 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_t
{
	char	*name;
	int		mode;
	struct s_t *next;
}		t_str;

t_str	*create_elem(char *content)
{
	t_str *node;
	struct stat sfile;

	node = (t_str*)malloc(sizeof(t_str));
	node->mode = 0;
	if (content)
	{
		node->name = malloc(sizeof(char) * ft_strlen(content) + 1);
		ft_strcpy(node->name, content);
		stat(content, &sfile);
		node->mode = sfile.st_mode;
	}
	else
		node->name = NULL;
	node->next = NULL;
	return (node);
}

void	add_to_end(t_str *head, t_str *node)
{
	while (head->next != NULL)
		head = head->next;
	head->next = node;
	node->next = NULL;	
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		DIR *ptr;
		struct dirent *pDir;
		t_str		*g;
		t_str		*head;
		struct stat sfile;

		g = create_elem(NULL);
		ptr = opendir(argv[1]);
		head = g;
		while ((pDir = readdir(ptr)) != NULL)
		{
			 stat(pDir->d_name, &sfile);
			 printf("st_mode: %o\n", sfile.st_mode);
			 g = create_elem(pDir->d_name);
			 add_to_end(head, g);
			 g = g->next;
		}
		closedir (ptr);
		while (head != NULL)
		{
			printf("%s  %o\n", head->name, head->mode);
			head = head->next;
		}
//		stat(argv[2], &sfile);
//		printf("st_mode:%o\n", sfile.st_mode);
	}
}
