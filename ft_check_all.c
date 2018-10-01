/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:44:38 by allallem          #+#    #+#             */
/*   Updated: 2017/12/16 14:26:21 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tabcheck(char **tab, int max)
{
	int i;
	int count;
	int j;

	j = 0;
	count = 0;
	i = 0;
	while (i < max)
	{
		while (tab[i][j])
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#')
				count++;
			if (tab[i][j] == '#' && tab[i][j + 5] == '#' && j < 15)
				count++;
			j++;
		}
		if (count < 3)
			return (0);
		count = 0;
		j = 0;
		i++;
	}
	return (1);
}

int		ft_checkdiese(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
			j++;
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			if (j != 4)
				return (0);
			j = 0;
		}
		i++;
	}
	if (j != 4 && str[i] == '\0')
		return (0);
	return (1);
}

int		ft_checkwidth(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == '#' || str[i] == '.')
			i++;
		if (str[i] == '\n')
		{
			j++;
			i++;
		}
		if ((str[i] == '\n' && str[i - 1] == '\n') || j > 4)
		{
			if (j != 4 || (str[i + 1] == '\n' && str[i] == '\n'))
				return (0);
			j = 0;
			i++;
		}
	}
	return (1);
}

int		ft_checklen(char *str)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] && j < 5 && (str[i] == '#' || str[i] == '.'))
	{
		count++;
		i++;
		j++;
		if (str[i] == '\n')
		{
			if (j != 4)
				return (0);
			while (str[i] == '\n')
				i++;
			j = 0;
		}
	}
	if (str[i] == '\0' && (count % 16) == 0)
		return (count / 16);
	return (0);
}
