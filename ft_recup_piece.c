/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:03:57 by allallem          #+#    #+#             */
/*   Updated: 2017/12/16 17:04:00 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_swaphash(char **newtab)
{
	int		i;
	int		j;
	char	c;

	c = 'A';
	i = 0;
	while (newtab[i])
	{
		j = 0;
		while (newtab[i][j])
		{
			if (newtab[i][j] == '#')
				newtab[i][j] = c;
			j++;
		}
		c++;
		i++;
	}
	return (newtab);
}

static int		ft_linehash(char *tab, int k)
{
	int count;

	count = 0;
	k = (k / 5) * 5;
	while (tab[k] != '\n')
	{
		if (tab[k] == '#' || tab[k] == '.')
			count++;
		k++;
	}
	if (count > 0)
		return (1);
	return (0);
}

static char		**ft_putform_tab(char **tab, char **newtab)
{
	int i;
	int j;
	int k;

	i = 0;
	while (tab[i])
	{
		j = 0;
		k = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != 'G' && ft_linehash(tab[i], j) > 0)
			{
				newtab[i][k] = tab[i][j];
				k++;
			}
			j++;
		}
		free(tab[i]);
		newtab[i][k] = '\0';
		i++;
	}
	free(tab);
	tab = NULL;
	return (newtab);
}

static char		**ft_malloc_tab_string(char **tab, char **newtab)
{
	int i;
	int j;
	int k;
	int l;

	l = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		k = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != 'G' && ft_linehash(tab[i], j) > 0)
				k++;
			j++;
		}
		if (!(newtab[l] = (char*)malloc(sizeof(char) * k + 1)))
			return (NULL);
		l++;
		i++;
	}
	return (newtab);
}

char			**ft_recup_piece(char **tab)
{
	char	**newtab;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if (!(newtab = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	newtab[i] = 0;
	ft_malloc_tab_string(tab, newtab);
	ft_putform_tab(tab, newtab);
	ft_swaphash(newtab);
	return (newtab);
}
