/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:37:43 by arafa             #+#    #+#             */
/*   Updated: 2024/09/16 13:23:17 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_removable(char *s)
{
	int	x;
	int	trigger;

	x = 0;
	trigger = 0;
	while (s[x])
	{
		if (s[x] == '1' || s[x] == '0')
			trigger++;
		x++;
	}
	if (!trigger)
		return (1);
	return (0);
}

char	*set_tab(char *tab)
{
	char	*temp;

	temp = ft_strtrim(tab, " 	");
	free(tab);
	return (temp);
}

int	is_printable(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (!(s[x] >= 48 && s[x] <= 57)
			&& !(s[x] >= 65 && s[x] <= 90)
			&& !(s[x] >= 97 && s[x] <= 122))
			return (0);
		x++;
	}
	return (1);
}
