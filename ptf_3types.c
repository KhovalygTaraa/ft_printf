/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_3types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:33:56 by hovalygta         #+#    #+#             */
/*   Updated: 2020/07/31 00:25:39 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_percent(t_specifiers *format)
{
	int	c;
	int	printed_char;
	int	i;

	c = '%';
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

char	*convert_x(unsigned int p, int *i)
{
	int				count;
	char			*ch;
	char			*print;
	unsigned int	a;

	print = NULL;
	count = 0;
	a = p;
	while ((a / 16) != 0 || count == 0)
	{
		a = p;
		p = (p / 16);
		if (!(ch = full_x(a - (p * 16))))
			return (NULL);
		if (!(print = ft_strjoin(print, ch)))
			return (NULL);
		free(ch);
		count++;
	}
	*i = count;
	return (print);
}

char	*convert_big_x(unsigned int p, int *i)
{
	int				count;
	char			*ch;
	char			*print;
	unsigned int	a;

	print = NULL;
	count = 0;
	a = p;
	while ((a / 16) != 0 || count == 0)
	{
		a = p;
		p = (p / 16);
		if (!(ch = full_big_x(a - (p * 16))))
			return (NULL);
		if (!(print = ft_strjoin(print, ch)))
			return (NULL);
		free(ch);
		count++;
	}
	*i = count;
	return (print);
}

char	*convert_p(unsigned long int p, int *i)
{
	int					count;
	char				*ch;
	char				*print;
	unsigned long int	a;

	print = NULL;
	count = 0;
	a = p;
	while ((a / 16) != 0 || count == 0)
	{
		a = p;
		p = (p / 16);
		if (!(ch = full_p(a - (p * 16))))
			return (NULL);
		if (!(print = ft_strjoin(print, ch)))
			return (NULL);
		free(ch);
		count++;
	}
	if (!(print = ft_strjoin(print, "x0")))
		return (NULL);
	*i = count;
	return (print);
}
