/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_in_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:04:13 by allallem          #+#    #+#             */
/*   Updated: 2017/12/17 19:50:31 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_changebackn(char *str, int i)
{
	int k;
	int end;
	int change;

	end = 21 * i;
	k = 21;
	change = 20;
	while (change < end - 1)
	{
		str[change] = '0';
		change = change + k;
	}
	return (str);
}

char	**ft_check(char *str)
{
	int		i;
	char	**tab;

	if ((!(i = ft_checklen(str)) || ft_checklen(str) > 26))
		return (NULL);
	if (!(ft_checkwidth(str)))
		return (NULL);
	if (!(ft_checkdiese(str)))
		return (NULL);
	ft_changebackn(str, i);
	tab = ft_strsplit(str, '0');
	free(str);
	if (!(ft_tabcheck(tab, i)))
		return (NULL);
	return (tab);
}

int		ft_taillemalloc(char *file)
{
	int		i;
	int		fd;
	char	buffer;
	char	tmp;

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &buffer, 1) > 0 && i < 600)
	{
		tmp = buffer;
		i++;
	}
	close(fd);
	if (tmp != '\n')
		return (0);
	return (i);
}

char	**ft_put_in_memory(char *file)
{
	int		fd;
	char	*str;
	char	buffer;
	char	**tab;
	int		i;

	i = 0;
	if ((!(str = (char*)malloc(sizeof(char) * ft_taillemalloc(file) + 1))) \
		|| ft_taillemalloc(file) == 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (read(fd, &buffer, 1) > 0 && i < 600)
	{
		str[i] = buffer;
		i++;
	}
	close(fd);
	str[i] = '\0';
	if ((tab = ft_check(str)) == NULL)
		return (NULL);
	return (tab);
}
