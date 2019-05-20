/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:54:53 by amarcel           #+#    #+#             */
/*   Updated: 2019/03/18 16:57:52 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block.h"

int		checkblock(t_tetrimino *tetrimino, char **grid, int pos, int size)
{
	int x;
	int y;
	int i;
	int j;

	x = pos % size;
	y = pos / size;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimino->block[j][i] == '#')
			{
				if (x + j >= size || y + i >= size)
					return (1);
				else if (grid[x + j][y + i] != '.')
					return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

void	removeblock(t_tetrimino *tetrimino, int position, char **grid, int size)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	c;

	x = position % size;
	y = position / size;
	i = 0;
	j = 0;
	c = '.';
	while (j < 4)
	{
		while (i < 4)
		{
			if (tetrimino->block[i][j] == '#')
				grid[x + i][y + j] = c;
			++i;
		}
		++j;
		i = 0;
	}
}

void	placeblock(t_tetrimino *tetrimino, int position, char **grid, int size)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	c;

	x = position % size;
	y = position / size;
	i = 0;
	j = 0;
	c = tetrimino->id;
	while (j < 4)
	{
		while (i < 4)
		{
			if (tetrimino->block[i][j] == '#')
				grid[x + i][y + j] = c;
			++i;
		}
		++j;
		i = 0;
	}
}
