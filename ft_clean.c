/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 11:57:12 by allallem          #+#    #+#             */
/*   Updated: 2017/12/16 14:26:13 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_incrementation(int i, int count)
{
	i = 0;
	count = 0;
}

int		ft_count(char **map)
{
	int j;
	int i;
	int count;

	count = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] >= 'A' && map[j][i] <= 'Z')
				count++;
			i++;
		}
		j++;
	}
	return (count / 4);
}

void	ft_delstr(char **map, char *str)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while (str[i] == '.')
		i++;
	while (map[j])
	{
		k = 0;
		while (map[j][k])
		{
			if (map[j][k] == str[i])
				map[j][k] = '.';
			k++;
		}
		j++;
	}
}

void	ft_cleanmap(char **map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
