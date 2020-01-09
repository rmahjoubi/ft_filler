/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:36:31 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/09/19 18:46:25 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	inis_piece(t_filler *filler)
{
	int i;
	int j;

	i = 0;
	while (i < filler->nmplins)
	{
		j = 0;
		while (j < filler->nmpcols)
		{
			filler->piece[i][j] = 3;
			j++;
		}
		i++;
	}
}

void	inis_board(t_filler *filler)
{
	int i;
	int j;

	i = 0;
	while (i < filler->nmlines)
	{
		j = 0;
		while (j < filler->nmcolumns)
		{
			filler->heatboard[i][j] = -9;
			filler->board[i][j] = 0;
			j++;
		}
		i++;
	}
}
