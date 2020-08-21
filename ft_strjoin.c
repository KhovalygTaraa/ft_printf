/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 14:46:39 by swquinc           #+#    #+#             */
/*   Updated: 2020/07/25 21:58:01 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char *s1, char const *s2)
{
	size_t		a;
	size_t		b;
	char		*s3;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((s3 = ft_strdup(s2)));
	if (!s2)
		return ((s3 = ft_strdup(s1)));
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!(s3 = malloc((a + b + 1) * sizeof(char))))
		return (0);
	a = -1;
	b = -1;
	while (s1[++a] != 0)
		s3[a] = s1[a];
	while (s2[++b] != 0)
		s3[a + b] = s2[b];
	s3[a + b] = 0;
	free(s1);
	s1 = NULL;
	return (s3);
}
