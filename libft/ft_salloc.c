/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_salloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:33:18 by hovalygta         #+#    #+#             */
/*   Updated: 2020/07/31 00:24:19 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_salloc(size_t size)
{
	char	*string;

	if (!(string = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	string[size] = '\0';
	return (string);
}
