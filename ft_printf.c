/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 12:10:44 by hovalygta         #+#    #+#             */
/*   Updated: 2020/07/31 00:26:19 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			dot_exist(t_specifiers *format)
{
	format->precision = 0;
	if (format->flag_zero == 1)
		format->flag_zero = 2;
	else
		format->flag_zero = 0;
}

static t_specifiers	*new_format(void)
{
	t_specifiers	*format;

	if (!(format = malloc(sizeof(t_specifiers))))
		return (NULL);
	format->flag_min = 0;
	format->flag_zero = 0;
	format->width = 0;
	format->precision = -1;
	return (format);
}

static int			parsing(t_specifiers *format, char *s, va_list arg)
{
	int	i;

	i = -1;
	while (s[++i] != 'c' && s[i] != 's' && s[i] != 'p' && s[i] != 'd' && s[i]
		!= 'i' && s[i] != 'u' && s[i] != 'x' && s[i] != 'X' && s[i] != '%')
	{
		if (s[i] == '-' && i >= 0 && i <= 1)
			format->flag_min = 1;
		if (s[i] == '0' && i == 0 && format->flag_min == 0)
			format->flag_zero = 1;
		if (s[i] == '*' && format->precision == -1)
			format->width = fill_width(arg, s[i], 1, format);
		if (s[i] >= 48 && s[i] <= 57 && format->precision == -1)
			format->width = fill_width(arg, s[i], 1, format);
		if (s[i] == '.')
			dot_exist(format);
		if (s[i] == ' ')
			ft_putchar_fd(' ', 1);
		if (s[i] == '*' && format->precision >= 0)
			format->precision = fill_precision(arg, s[i], 1, format);
		if (s[i] >= 48 && s[i] <= 57 && format->precision >= 0)
			format->precision = fill_precision(arg, s[i], 1, format);
	}
	fill_width(arg, 'a', 0, format);
	return (i);
}

static int			output(va_list args, char *spec, int *index)
{
	int				i;
	t_specifiers	*format;

	if (!(format = new_format()))
		return (0);
	i = parsing(format, spec, args);
	*index = *index + i;
	if (spec[i] == 'c')
		i = print_c(format, args);
	else if (spec[i] == 's')
		i = print_s(format, args);
	else if (spec[i] == 'p')
		i = print_p(format, args);
	else if (spec[i] == 'd' || spec[i] == 'i')
		i = print_di(format, args);
	else if (spec[i] == 'u')
		i = print_u(format, args);
	else if (spec[i] == 'x')
		i = print_x(format, args);
	else if (spec[i] == 'X')
		i = print_big_x(format, args);
	else if (spec[i] == '%')
		i = print_percent(format);
	free(format);
	return (i);
}

int					ft_printf(const char *src, ...)
{
	va_list		args;
	char		*format;
	int			printed_char;
	int			i;

	printed_char = 0;
	i = 0;
	if (!(format = ft_strdup(src)) || !src)
		return (-1);
	va_start(args, src);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			printed_char = printed_char + (output(args, &format[++i], &i));
		else
		{
			ft_putchar_fd(format[i], 1);
			printed_char++;
		}
		i++;
	}
	va_end(args);
	free(format);
	return (printed_char);
}
