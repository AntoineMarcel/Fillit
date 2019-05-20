/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:39:13 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 18:34:49 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verify_block.h"

int	verify_block(char buf[22])
{
	int	i;
	int	countdot;
	int	countend;

	i = 0;
	countdot = 0;
	countend = 0;
	while (buf[i])
	{
		if (verifyconnect(buf) < 6)
			return (-1);
		if (buf[i] == '.')
			countdot++;
		if (buf[i] == '\n')
			countend++;
		i++;
	}
	if (countdot == 12 && (countend == 5 || countend == 4))
		return (0);
	return (-1);
}

int	verifyconnect(char buf[22])
{
	int countconnect;
	int i;

	i = 0;
	countconnect = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (buf[i - 1] == '#')
				countconnect++;
			if (buf[i + 1] == '#')
				countconnect++;
			if (buf[i + 5] == '#')
				countconnect++;
			if (buf[i - 5] == '#')
				countconnect++;
		}
		i++;
	}
	return (countconnect);
}
