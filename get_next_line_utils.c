/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeeunkim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:24:12 by chaeeunkim        #+#    #+#             */
/*   Updated: 2021/02/20 16:55:05 by chaeeunki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t		srclen;
	size_t		i;

	srclen = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[srclen] != 0)
		srclen++;
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (srclen);
}

size_t		ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t i;
	size_t destlen;
	size_t srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (dstsize <= destlen)
		return (dstsize + srclen);
	while (src[i] && destlen + i + 1 < dstsize)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (destlen + srclen);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (*s1 != 0)
		ptr[i++] = *s1++;
	while (*s2 != 0)
		ptr[i++] = *s2++;
	ptr[i] = 0;
	return (ptr);
}
