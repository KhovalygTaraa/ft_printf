/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_1types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 18:38:09 by hovalygta         #+#    #+#             */
/*   Updated: 2020/07/31 00:24:46 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_c(t_specifiers *format, va_list args)
{
	int		c;
	int		printed_char;
	int		i;

	c = va_arg(args, int);
	i = format->width;
	printed_char = 0;
	if (i == 1 || i == 0)
		ft_putchar_fd(c, 1);
	if (i == 1 || i == 0)
		return (printed_char + 1);
	if (format->flag_min == 1)
		ft_putchar_fd(c, 1);
	while ((i - 1) != 0)
	{
		if (format->flag_zero == 1)
			ft_putchar_fd('0', 1);
		if (format->flag_zero == 0)
			ft_putchar_fd(' ', 1);
		i--;
		printed_char++;
	}
	if (format->flag_min == 0)
		ft_putchar_fd(c, 1);
	return (printed_char + 1);
}

int		print_s(t_specifiers *format, va_list args)
{
	char	*s;
	int		i;
	int		a;
	int		len;

	a = 0;
	i = format->precision;
	if (!(s = va_arg(args, char*)))
		s = "(null)";
	len = ft_strlen(s);
	if (i >= 0 && i < len)
		len = i;
	i = print_width_s(format, len);
	while (s[a] != 0 && len != 0)
	{
		ft_putchar_fd(s[a], 1);
		a++;
		len--;
	}
	a = a + i;
	i = print_width_s(format, (a - i));
	return (a + i);
}

int		print_di(t_specifiers *format, va_list args)
{
	int		di;
	int		i;
	int		printed_char;
	char	*str;

	i = -1;
	di = va_arg(args, int);
	if (!(str = ft_itoa(di)))
		return (0);
	printed_char = print_width(format, str, di);
	printed_char = printed_char + (print_precision(str, format, di));
	while (str[++i] != 0)
	{
		if (format->precision == 0 && di == 0 && format->width != 0)
			ft_putchar_fd(' ', 1);
		else if (format->precision == 0 && di == 0 && format->width == 0)
			break ;
		else
			ft_putchar_fd(str[i], 1);
		printed_char++;
	}
	printed_char = printed_char + (print_width(format, str, di));
	free(str);
	return (printed_char);
}

char	*full_p(unsigned long int a)
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

int		print_p(t_specifiers *format, va_list args)
{
	unsigned long int	p;
	int					printed_char;
	int					i;
	char				*print;

	p = va_arg(args, unsigned long int);
	if (!(print = convert_p(p, &i)))
		return (0);
	printed_char = print_width(format, print, 1);
	printed_char = printed_char + (print_precision(print, format, 1));
	ft_putstr_fd("0x", 1);
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
	return (printed_char + 2);
}
