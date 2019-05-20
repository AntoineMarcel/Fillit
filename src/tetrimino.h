/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:39:05 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 16:48:29 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef TETRIMINO_H
#	define TETRIMINO_H

#include <stdio.h>
#include "verify_block.h"
#include "../libft/libft.h"

typedef struct		s_tetrimino
{
	char			block[4][4];
	char			id;
}					t_tetrimino;

typedef struct		s_tetriminolist
{
	t_tetrimino		*list;
	int				size;
}					t_tetriminolist;

void				ft_addblock(char *src, t_tetrimino *dest);
void				ft_filllist(t_tetriminolist *tetri_list, char **str_tetri);
void				ft_blockup(t_tetrimino *tetri);
void				ft_blockleft(t_tetrimino *tetri);

#	endif
