/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_2types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 00:08:03 by hovalygta         #+#    #+#             */
/*   Updated: 2021/06/09 10:22:31 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		print_u(t_specifiers *format, va_list args)
{
	unsigned int	u;
	char			*str;
	int				i;
	int				printed_char;

	i = -1;
	u = va_arg(args, unsigned int);
	if (!(str = ft_uitoa(u)))
		return (0);
	printed_char = print_width(format, str, 1);
	printed_char = printed_char + (print_precision(str, format, 1));
	while (str[++i] != 0)
	{
		if (format->precision == 0 && u == 0 && format->width != 0)
			ft_putchar_fd(' ', 1);
		else if (format->precision == 0 && u == 0 && format->width == 0)
			break ;
		else
			ft_putchar_fd(str[i], 1);
		printed_char++;
	}
	printed_char = printed_char + (print_width(format, str, 1));
	free(str);
	return (printed_char);
}

char	*full_x(unsigned int a)
{
	char		*ch;
	char		*itoa;

	if (!(ch = ft_salloc(1)))
		return (NULL);
	if (a >= 0 && a <= 9)
	{
		if (!(itoa = ft_itoa(a)))
			return (NULL);
		ch[0] = itoa[0];
		free(itoa);
	}
	if (a == 10)
		ch[0] = 'a';
	if (a == 11)
		ch[0] = 'b';
	if (a == 12)
		ch[0] = 'c';
	if (a == 13)
		ch[0] = 'd';
	if (a == 14)
		ch[0] = 'e';
	if (a == 15)
		ch[0] = 'f';
	return (ch);
}

int		print_x(t_specifiers *format, va_list args)
{
	unsigned int	p;
	unsigned int	printed_char;
	int				i;
	char			*print;

	print = NULL;
	p = va_arg(args, unsigned int);
	if (!(print = convert_x(p, &i)))
		return (0);
	printed_char = print_width(format, print, i);
	printed_char = printed_char + (print_precision(print, format, i));
	while (--i != -1)
	{
		if (format->precision == 0 && p == 0 && format->width != 0)
			ft_putchar_fd(' ', 1);
		else if (format->precision == 0 && p == 0 && format->width == 0)
			break ;
		else
			ft_putchar_fd(print[i], 1);
		printed_char++;
	}
	printed_char = printed_char + (print_width(format, print, 1));
	free(print);
	return (printed_char);
}

char	*full_big_x(unsigned int a)
{
	char		*ch;
	char		*itoa;

	if (!(ch = ft_salloc(1)))
		return (NULL);
	if (a >= 0 && a <= 9)
	{
		if (!(itoa = ft_itoa(a)))
			return (NULL);
		ch[0] = itoa[0];
		free(itoa);
	}
	if (a == 10)
		ch[0] = 'A';
	if (a == 11)
		ch[0] = 'B';
	if (a == 12)
		ch[0] = 'C';
	if (a == 13)
		ch[0] = 'D';
	if (a == 14)
		ch[0] = 'E';
	if (a == 15)
		ch[0] = 'F';
	return (ch);
}

int		print_big_x(t_specifiers *format, va_list args)
{
	unsigned int	p;
	unsigned int	printed_char;
	char			*print;
	int				i;

	print = NULL;
	p = va_arg(args, unsigned int);
	if (!(print = convert_big_x(p, &i)))
		return (0);
	printed_char = print_width(format, print, i);
	printed_char = printed_char + (print_precision(print, format, i));
	while (--i != -1)
	{
		if (format->precision == 0 && p == 0 && format->width != 0)
			ft_putchar_fd(' ', 1);
		else if (format->precision == 0 && p == 0 && format->width == 0)
			break ;
		else
			ft_putchar_fd(print[i], 1);
		printed_char++;
	}
	printed_char = printed_char + (print_width(format, print, 1));
	free(print);
	return (printed_char);
}
