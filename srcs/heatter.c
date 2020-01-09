/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:54:22 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/08/09 17:19:48 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		heatsri(int **heatboard, t_cord cord, int nmlines, int nmcolumns)
{
	int cond;

	cond = 0;
	if (cord.x - 1 >= 0 && cord.y + 1 < nmcolumns
		&& heatboard[cord.x - 1][cord.y + 1] == -9 && (cond = 1))
		heatboard[cord.x - 1][cord.y + 1] = heatboard[cord.x][cord.y] + 1;
	if (cord.y - 1 >= 0 && cord.x + 1 < nmlines
		&& heatboard[cord.x + 1][cord.y - 1] == -9 && (cond = 1))
		heatboard[cord.x + 1][cord.y - 1] = heatboard[cord.x][cord.y] + 1;
	if (cord.x + 1 < nmlines
		&& heatboard[cord.x + 1][cord.y] == -9 && (cond = 1))
		heatboard[cord.x + 1][cord.y] = heatboard[cord.x][cord.y] + 1;
	if (cord.y + 1 < nmcolumns && cord.x + 1 < nmlines
		&& heatboard[cord.x + 1][cord.y + 1] == -9 && (cond = 1))
		heatboard[cord.x + 1][cord.y + 1] = heatboard[cord.x][cord.y] + 1;
	return (cond);
}

int		heatsr(int **heatboard, t_cord cord, int nmlines, int nmcolumns)
{
	int cond;

	cond = 0;
	if (cord.x - 1 >= 0 && heatboard[cord.x - 1][cord.y] == -9 && (cond = 1))
		heatboard[cord.x - 1][cord.y] = heatboard[cord.x][cord.y] + 1;
	if (cord.y - 1 >= 0 && heatboard[cord.x][cord.y - 1] == -9 && (cond = 1))
		heatboard[cord.x][cord.y - 1] = heatboard[cord.x][cord.y] + 1;
	if (cord.y - 1 >= 0 && cord.x - 1 >= 0 &&
		heatboard[cord.x - 1][cord.y - 1] == -9 && (cond = 1))
		heatboard[cord.x - 1][cord.y - 1] = heatboard[cord.x][cord.y] + 1;
	if (cord.y + 1 < nmcolumns &&
		heatboard[cord.x][cord.y + 1] == -9 && (cond = 1))
		heatboard[cord.x][cord.y + 1] = heatboard[cord.x][cord.y] + 1;
	if (heatsri(heatboard, cord, nmlines, nmcolumns))
		cond = 1;
	if (cond)
		return (1);
	return (0);
}

void	heat_board(int **heatboard, int id, int nmlines, int nmcolumns)
{
	t_cord	cord;
	int		cond;

	cord.x = 0;
	cord.y = 0;
	cond = 1;
	while (cond)
	{
		cond = 0;
		cord.x = 0;
		while (cord.x < nmlines)
		{
			cord.y = 0;
			while (cord.y < nmcolumns)
			{
				if (heatboard[cord.x][cord.y] == id)
					if (heatsr(heatboard, cord, nmlines, nmcolumns))
						cond = 1;
				cord.y++;
			}
			cord.x++;
		}
		id++;
	}
}
