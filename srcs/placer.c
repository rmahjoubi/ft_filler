/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:55:56 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/08/09 20:30:22 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_possi(t_filler *filler, t_cord d, t_cord c, int *cond)
{
	int cost;

	cost = 0;
	if (d.y + c.y < filler->nmcolumns
		&& c.x + d.x < filler->nmlines)
	{
		if (filler->board[c.x + d.x][d.y + c.y] != 1
			&& filler->board[c.x + d.x][d.y + c.y] != 2)
			if (filler->piece[d.x + filler->trim.x][d.y + filler->trim.y] == 1)
				cost = filler->heatboard[c.x + d.x][d.y + c.y];
		if (filler->board[c.x + d.x][d.y + c.y] == 2 &&
			filler->piece[d.x + filler->trim.x][d.y + filler->trim.y] == 1)
			return (-1);
		if (filler->board[c.x + d.x][d.y + c.y] == 1 &&
			filler->piece[d.x + filler->trim.x][d.y + filler->trim.y] == 1)
			if (--cond[0] != 1)
				return (-1);
	}
	return (cost);
}

int		check_poss(t_filler *filler, t_cord d)
{
	t_cord	c;
	int		cond;
	int		cost[2];

	c.x = 0;
	cond = 2;
	cost[0] = 0;
	while (!(c.y = 0) && c.x + filler->trim.x < filler->nmplins)
	{
		while (c.y + filler->trim.y < filler->nmpcols)
		{
			if (c.y + d.y < filler->nmcolumns && d.x + c.x < filler->nmlines)
			{
				if ((cost[1] = check_possi(filler, c, d, &cond)) == -1)
					return (-1);
				cost[0] += cost[1];
			}
			else if (filler->piece[c.x + filler->trim.x][c.y + filler->trim.y]
					!= 3)
				return (-1);
			c.y++;
		}
		c.x++;
	}
	return (cond == 1 ? cost[0] : -1);
}

int		great_wall(t_filler *filler)
{
	t_cord	cord;
	int		tmp;

	cord.x = 0;
	while (cord.x < filler->nmlines)
	{
		cord.y = 0;
		while (cord.y < filler->nmcolumns)
		{
			if ((tmp = check_poss(filler, cord)) != -1)
			{
				ft_putnbr(cord.x - filler->trim.x);
				ft_putchar(' ');
				ft_putnbr(cord.y - filler->trim.y);
				ft_putchar('\n');
				return (1);
			}
			cord.y++;
		}
		cord.x++;
	}
	return (0);
}

int		print_result(t_filler *filler, int lowcost)
{
	ft_putnbr(filler->ret.x - filler->trim.x);
	ft_putchar(' ');
	ft_putnbr(filler->ret.y - filler->trim.y);
	ft_putchar('\n');
	if (lowcost < 0)
		return (0);
	return (1);
}

int		find_best_pos(t_filler *filler)
{
	t_cord	cord;
	int		tmp;
	int		lowcost;

	cord.x = 0;
	lowcost = -1;
	filler->ret.x = 0;
	filler->ret.y = 0;
	while (cord.x < filler->nmlines)
	{
		cord.y = 0;
		while (cord.y < filler->nmcolumns)
		{
			if ((tmp = check_poss(filler, cord)) != -1
				&& (lowcost < 0 || tmp <= lowcost))
			{
				lowcost = tmp;
				filler->ret.x = cord.x;
				filler->ret.y = cord.y;
			}
			cord.y++;
		}
		cord.x++;
	}
	return (print_result(filler, lowcost));
}
