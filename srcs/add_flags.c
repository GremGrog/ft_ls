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

int		add_flags(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] != '-')
		return (-1);
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
		i++;
	}
	if (g_flags == 0)
		return (0);
	else
		return (1);
}
