/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_flags2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 01:21:06 by hovalygta         #+#    #+#             */
/*   Updated: 2021/06/09 10:22:00 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	zero01(int i, int len, int printed_char, t_specifiers *format)
{
	format->flag_min = 2;
	if (format->precision > 0)
		format->flag_zero = 0;
	while (i != len)
	{
		if (format->flag_zero == 0)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd('0', 1);
		printed_char++;
		i--;
	}
	return (printed_char);
}
