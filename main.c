/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:22:03 by allallem          #+#    #+#             */
/*   Updated: 2017/12/17 19:53:27 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**tab;
	int		i;

	i = 0;
	if (argc == 2)
	{
		if (!(tab = ft_put_in_memory(argv[1])))
		{
			ft_putstr("error\n");
			return (0);
		}
		tab = ft_get_form_tab(tab);
		while (tab[i])
			i++;
		ft_placepiece(tab, ft_sqrt((i + 1) * 4));
		ft_cleanmap(tab);
	}
	else
		ft_putstr("usage: ./fillit target_file\n");
	return (0);
}
