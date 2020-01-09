/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:32:05 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/09/21 00:36:08 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"

typedef struct	s_cord
{
	int 		x;
	int 		y;
}				t_cord;

typedef struct	s_filler
{
	char		pid;
	int			nmlines;
	int			nmcolumns;
	int			**board;
	int			**heatboard;
	int			**infboard;
	int			**piece;
	int			nmplins;
	int			nmpcols;
	t_cord		trim;
	t_cord		ret;
}				t_filler;

void			influence_reg(t_filler *filler);
int				get_id(char *line, char *id, t_filler *filler);	
int				get_piece_size(char *line, char *kword, t_filler *filler);
int				get_board_size(char *line, char *kword, t_filler *filler);
int				getter(t_filler *filler, int (*gett)(char *line, char *strr, t_filler *filler), char *str);
int				board_alloc(int ***board, int nmlines, int nmcolumns);
void			board_free(int ***board, int nmlines, int nmcolumns);
int				fill_line_board(char *line, t_filler *filler, int j);
int				fill_line_piece(char *line, t_filler *filler, int j);
int				updatter(int **board, int nmlines, int (*updatt)(char *line, t_filler *filler, int j), t_filler *filler);
void			heat_board(int **heatboard, int id, int nmlines, int nmcolumns);
int				check_poss(t_filler *filler, t_cord cord);
int				find_best_pos(t_filler *filler);
void			trim_piece(t_filler *filler);
int				great_wall(t_filler *filler);
void			inis_piece(t_filler *filler);
void			inis_board(t_filler *filler);

#endif
