/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:07:59 by joncurci          #+#    #+#             */
/*   Updated: 2024/09/16 13:31:52 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strtrim(char const *s1, char const *set);

void	*ft_memset(void *b, int c, size_t len);

void	*ft_calloc(size_t count, size_t size)
{
	size_t	b;
	void	*p;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	b = count * size;
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	else
		ft_memset(p, 0, b);
	return (p);
}

static size_t	setcountbeg(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			if (s1[i] != set[j])
				j++;
		}
		if (set[j] == '\0')
			break ;
	}
	return (i);
}

static size_t	setcountend(char const *s1, char const *set)
{
	int		setlen;
	size_t	s1len;

	s1len = ft_strlen(s1) - 1;
	while (s1len >= 0)
	{
		setlen = ft_strlen(set) - 1;
		while (setlen >= 0)
		{
			if (s1[s1len] == set[setlen])
			{
				s1len--;
				break ;
			}
			if (s1[s1len] != set[setlen])
				setlen--;
		}
		if (setlen == -1)
			break ;
	}
	return (ft_strlen(s1) - (s1len + 1));
}

static size_t	memorylen(char const *s1, char const *set)
{
	size_t	trimlen;
	size_t	memlen;

	trimlen = setcountend(s1, set) + setcountbeg(s1, set);
	memlen = ft_strlen(s1) - trimlen;
	return (memlen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	memlen;
	char	*string;
	size_t	start;

	i = 0;
	if (!s1 || !s1[0])
		return (NULL);
	start = setcountbeg(s1, set);
	memlen = memorylen(s1, set);
	string = ft_substr(s1, start, memlen);
	return (string);
}
