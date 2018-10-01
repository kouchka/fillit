/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:56:59 by allallem          #+#    #+#             */
/*   Updated: 2017/12/16 14:26:39 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_bn(char *tab)
{
	int bn;
	int i;

	i = 0;
	bn = 0;
	while (tab[i] != '\n')
	{
		if (tab[i] == '.')
			i++;
		else
		{
			bn++;
			i++;
		}
	}
	return (bn);
}

int		ft_bn_bis(char *tab)
{
	int i;

	i = 0;
	while (tab[i] != '\n')
		i++;
	return (i);
}

void	ft_put(char *tab, char **map, int i, int j)
{
	int k;
	int bn;

	bn = ft_bn_bis(tab);
	k = 0;
	while (tab[k])
	{
		if (tab[k] != '.' && tab[k] != '\n' && map[j][i] == '.')
		{
			map[j][i] = tab[k];
			i++;
		}
		if (tab[k] == '.')
			i++;
		if (tab[k] == '\n' && tab[k + 1] != '\0')
		{
			j++;
			i = i - bn;
		}
		k++;
	}
}
