/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 01:47:11 by swquinc           #+#    #+#             */
/*   Updated: 2020/07/29 03:13:22 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lvl(unsigned int n)
{
	int	i;

	i = 1;
	if (n == 1)
		return (1);
	while (n > 1)
	{
		i = i * 10;
		n--;
	}
	return (i);
}

static int	len(unsigned int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_uitoa(unsigned int n)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	i;
	char			*string;

	a = len(n);
	b = a;
	i = 0;
	if (!(string = (char*)malloc(sizeof(char) * (a + 1))))
		return (0);
	if (n < 0)
	{
		n = n * -1;
		n = 4294967295 - n;
	}
	while (i < a)
		string[i++] = (((n / lvl(b--) % 10) + 48));
	string[i] = 0;
	return (string);
}
