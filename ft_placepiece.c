/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placepiece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:52:40 by allallem          #+#    #+#             */
/*   Updated: 2017/12/17 19:59:32 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_seeplace(char *tab, char **map, int i, int j)
{
	int k;
	int count;
	int tmp;

	tmp = i;
	count = 0;
	k = 0;
	while (tab[k])
	{
		if (tab[k] >= 'A' && tab[k] <= 'Z' && map[j][i] == '.')
			ft_incrementation(++i, ++count);
		if (tab[k] == '\n')
		{
			if (count == 4 && tab[k + 1] == '\0')
				return (count);
			if (map[j + 1] == NULL)
				return (0);
			i = tmp;
			j++;
		}
		if (tab[k] == '.')
			i++;
		k++;
	}
	return (0);
}

int		ft_put_in_map(char **tab, char **map, int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tab[count] == 0)
		return (1);
	while (map[j])
	{
		while (map[j][i])
		{
			if (ft_seeplace(tab[count], map, i, j))
			{
				ft_put(tab[count], map, i, j);
				if (ft_put_in_map(tab, map, count + 1))
					return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (count > 0)
		ft_delstr(map, tab[count - 1]);
	return (0);
}

char	**ft_start_map(char **map, int nbr)
{
	int i;
	int j;

	i = 0;
	while (i < nbr)
	{
		j = 0;
		while (j < nbr)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\n';
		map[i][j + 1] = '\0';
		i++;
	}
	return (map);
}

char	**ft_createmap(int nbr)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char *) * (nbr + 1))))
		return (NULL);
	map[nbr] = 0;
	while (i < nbr)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (nbr + 1))))
			return (NULL);
		map[i][nbr] = '\0';
		i++;
	}
	ft_start_map(map, nbr);
	i = 0;
	return (map);
}

char	**ft_placepiece(char **tab, int mapsize)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_createmap(mapsize);
	ft_put_in_map(tab, map, 0);
	if (ft_count(map) == 0)
	{
		ft_cleanmap(map);
		ft_placepiece(tab, mapsize + 1);
	}
	else
	{
		while (i < mapsize)
		{
			ft_putstr(map[i]);
			i++;
		}
		ft_cleanmap(map);
	}
	return (map);
}
