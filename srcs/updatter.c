/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:52:28 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/08/09 17:09:18 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	fill_line_boardi(char *line, t_filler *filler, int j)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (line[i] != '\0' && k < filler->nmcolumns)
	{
		if (line[i] == filler->pid || line[i] == filler->pid + 'A' - 'a')
			filler->heatboard[j][k++] = -9;
		else if (line[i] == 'x' || line[i] == 'o' ||
				line[i] == 'X' || line[i] == 'O')
			filler->heatboard[j][k++] = -1;
		else if (line[i] == '.')
			filler->heatboard[j][k++] = -9;
		i++;
	}
}

int		fill_line_board(char *line, t_filler *filler, int j)
{
	int i;
	int k;

	k = 0;
	i = 0;
	if (j == 0)
		inis_board(filler);
	while (line[i] != '\0' && k < filler->nmcolumns)
	{
		if (line[i] == filler->pid || line[i] == filler->pid + 'A' - 'a')
			filler->board[j][k++] = 1;
		else if (line[i] == 'x' || line[i] == 'o' ||
				line[i] == 'X' || line[i] == 'O')
			filler->board[j][k++] = 2;
		else if (line[i] == '.')
			filler->board[j][k++] = 0;
		i++;
	}
	fill_line_boardi(line, filler, j);
	ft_memdel((void**)&line);
	if (k || j)
		return (1);
	return (0);
}

int		fill_line_piece(char *line, t_filler *filler, int j)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (j == 0)
		inis_piece(filler);
	while (line[i] != '\0' && k < filler->nmpcols)
	{
		if (line[i] == '*')
		{
			filler->piece[j][k] = 1;
			k++;
		}
		else if (line[i] == '.')
		{
			filler->piece[j][k] = 3;
			k++;
		}
		i++;
	}
	ft_memdel((void**)&line);
	if (k || j)
		return (1);
	return (0);
}

int		updatter(int **board, int nmlines,
		int (*updatt)(char *line, t_filler *filler, int j), t_filler *filler)
{
	char	buff[2];
	char	*line;
	int		t[3];
	char	*strtmp;

	t[1]  = 0;
	t[2] = 1;
	(void)board;
	while ((t[0] = read(0, buff, 1)))
	{
		if (t[2] && !(line = (char*)ft_memalloc(1)))
			return (0);
		t[2] = 0;
		buff[1] = '\0';
		strtmp = ft_strjoin(line, buff);
		ft_memdel((void**)&line);
		if (!strtmp)
			return (0);
		line = strtmp;
		if (buff[0] == '\n' && (t[2] = 1))
			if (updatt(line, filler, t[1]) && (++t[1] || 1) && t[1] == nmlines)
				return (1);
	}
	if (line && updatt(line, filler, t[1]) && (++t[1] || 1) && t[1] == nmlines)
		return (1);
	return (0);
}
