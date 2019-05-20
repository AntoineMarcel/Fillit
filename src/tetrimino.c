/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:39:00 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 15:39:02 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"

void	ft_addblock(char *src, t_tetrimino *dest)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 19)
	{
		if (src[i] != '\n')
		{
			dest->block[x][y] = src[i];
			x++;
		}
		else
		{
			y++;
			x = 0;
		}
		i++;
	}
}

void	ft_filllist(t_tetriminolist *tetri_list, char **str_tetri)
{
	int		i;
	char	id;

	id = 'A';
	i = 0;
	while (i < tetri_list->size)
	{
		ft_addblock(str_tetri[i], &tetri_list->list[i]);
		tetri_list->list[i].id = id;
		ft_blockleft(&tetri_list->list[i]);
		ft_blockup(&tetri_list->list[i]);
		++i;
		id++;
	}
}

void	ft_blockleft(t_tetrimino *tetri)
{
	int	y;
	int n;
	int	x;

	y = 0;
	x = 0;
	while (x < 4)
	{
		if (tetri->block[x][y] != '#' && tetri->block[x][y + 1] != '#'
		&& tetri->block[x][y + 2] != '#' && tetri->block[x][y + 3] != '#')
		{
			n = x + 1;
			while (y < 4 && n < 4)
			{
				ft_swap(&tetri->block[x][y], &tetri->block[n][y]);
				y++;
			}
		}
		x++;
		y = 0;
	}
	if (tetri->block[0][y] != '#' && tetri->block[0][y + 1] != '#'
	&& tetri->block[0][y + 2] != '#' && tetri->block[0][y + 3] != '#')
		ft_blockleft(tetri);
}

void	ft_blockup(t_tetrimino *tetri)
{
	int y;
	int n;
	int	x;

	y = 0;
	x = 0;
	while (y < 4)
	{
		if (tetri->block[x][y] != '#' && tetri->block[x + 1][y] != '#'
		&& tetri->block[x + 2][y] != '#' && tetri->block[x + 3][y] != '#')
		{
			n = y + 1;
			while (x < 4 && n < 4)
			{
				ft_swap(&tetri->block[x][y], &tetri->block[x][n]);
				x++;
			}
		}
		y++;
		x = 0;
	}
	if (tetri->block[x][0] != '#' && tetri->block[x + 1][0] != '#'
	&& tetri->block[x + 2][0] != '#' && tetri->block[x + 3][0] != '#')
		ft_blockup(tetri);
}
