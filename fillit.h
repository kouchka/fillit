/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:01:44 by allallem          #+#    #+#             */
/*   Updated: 2017/12/16 17:02:55 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

void	ft_incrementation(int i, int count);
int		ft_count(char **map);
void	ft_delstr(char **map, char *str);
int		ft_bn(char *tab);
char	**ft_placepiece(char **tab, int mapsize);
char	**ft_put_in_memory(char *list);
int		ft_checklen(char *str);
int		ft_checkwidth(char *str);
int		ft_checkdiese(char *str);
int		ft_tabcheck(char **str, int i);
char	**ft_get_form_tab(char **tab);
char	**ft_recup_piece(char **tab);
void	ft_cleanmap(char **map);
void	ft_put(char *tab, char **map, int i, int j);

#endif
