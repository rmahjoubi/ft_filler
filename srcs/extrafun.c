/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrafun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:01:03 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/08/09 21:36:44 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	board_free(int ***board, int nmlines, int nmcolumns)
{
	int i;

	i = 0;
	(void)nmcolumns;
	if (!board[0])
		return ;
	while (i < nmlines)
	{
		free(board[0][i]);
		i++;
	}
	free(board[0]);
	board[0] = NULL;
}

int		board_alloc(int ***board, int nmlines, int nmcolumns)
{
	int i;

	i = 0;
	if (!(board[0] = (int**)malloc(sizeof(int*) * nmlines)))
		return (0);
	while (i < nmlines)
	{
		if (!(board[0][i] = (int*)malloc(sizeof(int) * nmcolumns)))
		{
			while (i >= 0)
			{
				i--;
				free(board[0][i]);
			}
			free(board[0]);
			board[0] = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

void	inis_trim(t_filler *filler)
{
	filler->trim.x = -1;
	filler->trim.y = -1;
}

void	trim_piece(t_filler *filler)
{
	int i;
	int j;

	i = 0;
	inis_trim(filler);
	while (i < filler->nmplins)
	{
		j = 0;
		while (j < filler->nmpcols)
		{
			if (filler->piece[i][j] == 1)
			{
				if (filler->trim.x > i || filler->trim.x < 0)
					filler->trim.x = i;
				if (filler->trim.y > j || filler->trim.y < 0)
					filler->trim.y = j;
			}
			j++;
		}
		i++;
	}
	if (filler->trim.x < 0)
		filler->trim.x = 0;
	if (filler->trim.y < 0)
		filler->trim.y = 0;
}
