/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohter_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:36:02 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/19 15:10:01 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void				set_arr_to_null(char *arr, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

// int					ft_binpow(long a, long n)
// {
// 	long			res;

// 	res = 1;
// 	while (n)
// 	{
// 		if (n & 1)
// 			res *= a;
// 		a *= a;
// 		n >>= 1;
// 	}
// 	return (res);
// }

// void				ft_copy_float(char *x, short sign)
// {
// 	int				i;
// 	int				j;
// 	int				o;
// 	int				l;

// 	j = 0;
// 	i = 0;
// 	o = 199;
// 	while (x[i] == 0)
// 		i++;
// 	while (x[o] == 0)
// 		o--;
// 	l = o - i;
// 	check_and_add(g_buffer->str_len + l);
// 	if (sign == 1)
// 	{
// 		g_buffer->str[j] = '-';
// 		j = 1;
// 	}
// 	while (l >= 0)
// 		g_buffer->str[j++] = x[l--] + '0';
// 	g_buffer->str_len = l;
// 	free(x);
// }

void				other_case(char *y, short exp, short sign)
{
	int				n;
	char			*x;
	char			*z;
    char			*pow;
	char			*bow;
	
    
	n = exp - 52;
	if (!(x = (char*)malloc(sizeof(char) * 399)))
		return ;
	if (!(z = (char*)malloc(sizeof(char) * 399)))
	{
		free(x);
		free(z);
		free(y);
		return ;
	}
	pow = (char *)malloc(sizeof(char) * 399);
	bow = (char *)malloc(sizeof(char) * 399);
	set_arr_to_null(x, 400);
	set_arr_to_null(z, 400);
	set_arr_to_null(pow, 400);
	set_arr_to_null(bow, 400);
	pow = get_two_power(n, pow, bow);
	multiplication_long(y, pow, x);
	free(z);
	free(y);
	free(pow);
	ft_copy_float(x, sign);
}

void				validity(double flo)
{
	if (flo == 1.0 / 0.0)
	{
		ft_strcpy(g_buffer->str, "inf");
		g_buffer->str_len = 3;
	}
	else if (flo == -1.0 / 0.0)
	{
		ft_strcpy(g_buffer->str, "-inf");
		g_buffer->str_len = 4;
	}
	else if (flo != flo)
	{
		ft_strcpy(g_buffer->str, "nan");
		g_buffer->str_len = 3;
	}
}