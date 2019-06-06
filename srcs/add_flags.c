/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:22:48 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/06/02 20:22:51 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		add_flags_loop(char *argv, int i)
{
	while (argv[i] != '\0')
	{
		if (argv[i] == 'a')
			PUT_BIT(g_flags, 0);
		else if (argv[i] == 'r')
			PUT_BIT(g_flags, 1);
		else if (argv[i] == 't')
			PUT_BIT(g_flags, 2);
		else if (argv[i] == 'l')
			PUT_BIT(g_flags, 3);
		else if (argv[i] == 'R')
			PUT_BIT(g_flags, 4);
		else
		{
			g_flags = 0;
			break ;
		}
		i++;
	}
	return (i);
}

int		add_flags(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] != '-' || argv[i + 1] == '\0')
		return (-1);
	i = add_flags_loop(argv, i + 1);
	if (g_flags == 0)
	{
		ft_printf("./ft_ls: illegal option -- %c\n", argv[i]);
		ft_printf("usage: ./ft_ls [-Ralrt] [file ...]\n");
		exit(1);
	}
	return (1);
}
