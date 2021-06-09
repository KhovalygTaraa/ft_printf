/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:48:53 by hovalygta         #+#    #+#             */
/*   Updated: 2021/06/09 10:21:49 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	fill_width(va_list arg, char num, int z, t_specifiers *format)
{
	static int	full_number;
	static int	flag;

	if (z == 0)
	{
		fill_precision(arg, 'a', 0, format);
		full_number = 0;
		flag = 0;
		return (0);
	}
	if (num == '*')
	{
		if ((full_number = va_arg(arg, int)) < 0)
		{
			format->flag_zero = 0;
			format->flag_min = 1;
			full_number = full_number * -1;
		}
		flag = 1;
	}
	if (flag == 0)
		full_number = (full_number * 10 + (num - 48));
	return (full_number);
}

int	fill_precision(va_list arg, char num, int z, t_specifiers *f)
{
	static int	full_number;
	static int	flag;

	if (z == 0)
	{
		full_number = 0;
		flag = 0;
		return (0);
	}
	if (num == '*')
	{
		if ((full_number = va_arg(arg, int)) < 0)
		{
			if (f->flag_zero == 2)
				f->flag_zero = 1;
		}
		else
			f->flag_zero = 0;
		flag = 1;
	}
	if (flag == 0)
		full_number = (full_number * 10 + (num - 48));
	return (full_number);
}

int	print_precision(char *str, t_specifiers *format, int di)
{
	int		printed_char;
	int		len;
	int		i;

	printed_char = 0;
	len = ft_strlen(str);
	i = format->precision;
	if (i >= len)
	{
		if (di < 0)
		{
			ft_putchar_fd('-', 1);
			str[0] = '0';
			printed_char = printed_char + 1;
		}
		while (i-- != len)
		{
			ft_putchar_fd('0', 1);
			printed_char++;
		}
	}
	return (printed_char);
}

int	print_width_s(t_specifiers *format, int len)
{
	int		printed_char;
	int		i;

	printed_char = 0;
	i = format->width;
	if (i > len && format->flag_min == 0)
	{
		while (i != len)
		{
			if (format->flag_zero == 0)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd('0', 1);
			i--;
			printed_char++;
		}
		format->flag_min = 2;
	}
	if (format->flag_min == 1)
		format->flag_min = 0;
	return (printed_char);
}

int	print_width(t_specifiers *format, char *str, int di)
{
	int		printed_char;
	int		i;
	int		len;

	len = ft_strlen(str);
	if (format->precision > len)
		len = format->precision;
	if (di < 0 && format->precision >= len)
		len++;
	printed_char = 0;
	i = format->width;
	if (i > len && format->flag_min == 0)
	{
		if (di < 0 && format->flag_zero == 1)
		{
			str[0] = '0';
			len++;
			ft_putchar_fd('-', 1);
			printed_char++;
		}
		printed_char = zero01(i, len, printed_char, format);
	}
	if (format->flag_min == 1)
		format->flag_min = 0;
	return (printed_char);
}
