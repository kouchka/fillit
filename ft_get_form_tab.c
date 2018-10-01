/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_form_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:58:50 by allallem          #+#    #+#             */
/*   Updated: 2017/12/16 17:02:42 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_swappoint(char *str, int start, int i)
{
	int count;

	count = 0;
	while (count < 4 && i == 1)
	{
		str[start] = 'G';
		start++;
		count++;
	}
	while (count < 4 && i == 5)
	{
		str[start] = 'G';
		start += i;
		count++;
	}
	return (str);
}

char	**ft_swapcheck_y(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '\n')
		{
			if (tab[i][j] != '#' && tab[i][j + 5] != '#'
				&& tab[i][j + 10] != '#' && tab[i][j + 15] != '#')
				ft_swappoint(tab[i], j, 5);
			j++;
		}
		i++;
	}
	return (tab);
}

char	**ft_swapcheck_x(char **tab)
{
	int i;
	int j;
	int f;

	i = 0;
	while (tab[i])
	{
		j = 0;
		f = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '.')
				f++;
			if (tab[i][j] == '\n' && f == 4)
				ft_swappoint(tab[i], j - f, 1);
			if (tab[i][j] == '\n')
				f = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

char	**ft_get_form_tab(char **tab)
{
	ft_swapcheck_x(tab);
	ft_swapcheck_y(tab);
	return (ft_recup_piece(tab));
}
