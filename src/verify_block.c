/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:39:13 by abelkhay          #+#    #+#             */
/*   Updated: 2019/05/20 21:08:09 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verify_block.h"

int	verify_block(char *buf, int ret)
{
	int	i;
	int	countdot;
	int	countend;

	i = 0;
	countdot = 0;
	countend = 0;
	while (buf[i])
	{
		if (verifyconnect(buf, ret) < 6)
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

int	verifyconnect(char *buf, int ret)
{
	int countconnect;
	int i;

	i = 0;
	countconnect = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (i >= 1 && buf[i - 1] == '#')
				countconnect++;
			if (i + 1 < ret && buf[i + 1] == '#')
				countconnect++;
			if (i + 5 < ret && buf[i + 5] == '#')
				countconnect++;
			if (i >= 5 && buf[i - 5] == '#')
				countconnect++;
		}
		i++;
	}
	return (countconnect);
}
