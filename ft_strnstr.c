/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:59:47 by swquinc           #+#    #+#             */
/*   Updated: 2020/07/29 14:27:27 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!*needle)
		return ((char*)stack);
	while (stack[a] != 0 && a < len)
	{
		if (stack[a] == needle[0])
		{
			b = 0;
			while (stack[a + b] == needle[b] && (a + b) < len)
			{
				if (needle[b + 1] == 0)
					return ((char*)&stack[a]);
				b++;
			}
		}
		a++;
	}
	return (0);
}
