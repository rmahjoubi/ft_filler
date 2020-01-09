/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:57:52 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/08/09 15:17:22 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		f_play(t_filler *filler, int k)
{
	int ret;

	ret = 0;
	if (!(updatter(filler->board, filler->nmlines, &fill_line_board, filler)))
		return (0);
	heat_board(filler->heatboard, -1, filler->nmlines, filler->nmcolumns);
	if (!getter(filler, &get_piece_size, "Piece"))
		return (0);
	if (!board_alloc(&filler->piece, filler->nmplins, filler->nmpcols))
		return (0);
	if (!(updatter(filler->piece, filler->nmplins, &fill_line_piece, filler)))
	{
		board_free(&filler->piece, filler->nmplins, filler->nmpcols);
		return (0);
	}
	trim_piece(filler);
	if (k < 20 && filler->pid == 'x' &&
		filler->nmlines < 50 && great_wall(filler))
		ret = 1;
	else if (find_best_pos(filler))
		ret = 1;
	board_free(&filler->piece, filler->nmplins, filler->nmpcols);
	return (ret);
}

void	inis_all_boards(t_filler *filler)
{
	filler->board = NULL;
	filler->heatboard = NULL;
	filler->infboard = NULL;
}

void	free_all_boards(t_filler *filler)
{
	board_free(&filler->board, filler->nmlines, filler->nmcolumns);
	board_free(&filler->heatboard, filler->nmlines, filler->nmcolumns);
	board_free(&filler->infboard, filler->nmlines, filler->nmcolumns);
}

int		main(void)
{
	t_filler	filler;
	int			i;

	if (!getter(&filler, &get_id, "rmahjoub.filler"))
		return (0);
	if (!getter(&filler, &get_board_size, "Plateau"))
		return (0);
	if (!board_alloc(&filler.board, filler.nmlines, filler.nmcolumns) ||
		!board_alloc(&filler.heatboard, filler.nmlines, filler.nmcolumns) ||
		!board_alloc(&filler.infboard, filler.nmlines, filler.nmcolumns))
	{
		free_all_boards(&filler);
		return (0);
	}
	i = 0;
	while (1)
	{
		if (!f_play(&filler, i))
		{
			free_all_boards(&filler);
			return (0);
		}
		i++;
	}
}
