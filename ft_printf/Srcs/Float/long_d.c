/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:21 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/19 18:24:26 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void					copy_long_double(char *x, short sign)
{
	int		i;
	int		j;
	int		o;
	int		l;

	j = 0;
	i = 0;
	o = 4998;
	while (x[i] == 0)
		i++;
	while (x[o] == 0)
		o--;
	if (i == 1)
		i--;
	l = o - i;
	check_and_add(g_buffer->str_len + l);
	if (sign == 1)
		g_buffer->str[j++] = '-';
	while (l >= 0)
		g_buffer->str[j++] = x[l--] + '0';
	g_buffer->str_len = j;
	get_ipart();
	free(x);
}

void					set_arrays_to_null(char *a, char *b, int n)
{
	set_arr_to_null(a, n);
	set_arr_to_null(b, n);
}

void					get_dfloat_other(unsigned long long m, short e, short s)
{
	char	*arr;
	char	*pow;
	char	*bow;
	char	*z;
	char	*five;

	pow = (char *)malloc(sizeof(char) * 4999);
	bow = (char *)malloc(sizeof(char) * 4999);
	five = (char *)malloc(sizeof(char) * 4999);
	arr = (char *)malloc(sizeof(char) * 4999);
	z = (char *)malloc(sizeof(char) * 4999);
	set_arrays_to_null(pow, bow, 5000);
	set_arrays_to_null(arr, five, 5000);
	set_arr_to_null(z, 5000);
	pow = get_two_power_ld(e, pow, bow);
	number_to_arr(m, arr);
	multiplication_long_ld(arr, pow, z);
	set_arr_to_null(arr, 5000);
	free(pow);
	pow = (char *)malloc(sizeof(char) * 4999);
	bow = (char *)malloc(sizeof(char) * 4999);
	set_arrays_to_null(pow, bow, 5000);
	pow = get_five_power_ld(63, 0, pow, bow);
	multiplication_long_ld(z, pow, arr);
	set_arr_to_null(z, 5000);
	div_ld(arr, 63, z);
	copy_long_double(z, s);
	free(arr);
	free(pow);
	free(five);
}

void					get_dfloat(unsigned long long m, short exp, short sign)
{
	char	*arr;
	char	*pow;
	char	*bow;
	char	*z;

	if (63 - exp > 0)
	{
		if (!(arr = (char *)malloc(sizeof(char) * 399)))
			return ;
		if (!(pow = (char *)malloc(sizeof(char) * 399)))
		{
			free(arr);
			return ;
		}
		if (!(bow = (char *)malloc(sizeof(char) * 399)))
		{
			free(pow);
			free(arr);
			return ;
		}
		if (!(z = (char *)malloc(sizeof(char) * 399)))
		{
			free(pow);
			free(arr);
			free(bow);
			return ;
		}
		set_arrays_to_null(pow, bow, 400);
		set_arrays_to_null(z, arr, 400);
		pow = get_five_power(63, exp, pow, bow);
		number_to_arr(m, arr);
		multiplication_long(arr, pow, z);
		free(arr);
		free(pow);
		ft_copy_float(z, sign);
	}
	else
		get_dfloat_other(m, exp, sign);
}

void					long_double_work(t_pf *data, va_list args)
{
	long double			fl;
	__int128			*ptr;
	short				sign;
	short				exp;
	unsigned long long	mant;

	fl = (long double)va_arg(args, long double);
	ptr = (__int128 *)&fl;
	sign = (*ptr) >> 79;
	if (sign == 1)
		fl *= (-1);
	g_ipart = (__int128)fl;
	exp = ((*ptr) >> 64) - 16383;
	mant = (unsigned long long)*ptr;
	if (data->precision == 0)
		data->precision = 6;
	if (fl != 0 && fl != 1.0 / 0.0 && fl != -1.0 / 0.0 && fl == fl)
		get_dfloat(mant, exp, sign);
	else if (fl != 1.0 / 0.0 && fl != -1.0 / 0.0 && fl == fl)
		ipart_to_str();
	if (g_buffer->str[0] == '-')
		DEL_BIT(data->flags, 3);
}
