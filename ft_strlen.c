/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:18:51 by swquinc           #+#    #+#             */
/*   Updated: 2020/07/28 01:48:41 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	size_t count;

	if (!string)
		return (0);
	count = 0;
	while (string[count] != '\0')
	{
		count++;
	}
	return (count);
}
