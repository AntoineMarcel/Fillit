/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:38:52 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 17:14:40 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef READ_FILE_H
#	define READ_FILE_H

#include <stdlib.h>
#include <fcntl.h>

#include "verify_block.h"
#include "../libft/libft.h"

int		read_file(char *filename, char **str_tetri, int *tetri_counter);

#	endif
