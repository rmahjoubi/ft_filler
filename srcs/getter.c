/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:50:07 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/08/09 16:00:15 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_id(char *line, char *id, t_filler *filler)
{
	if (ft_strstr(line, id))
	{
		if (ft_strstr(line, "p1"))
		{
			filler->pid = 'o';
			ft_memdel((void**)&line);
			return (1);
		}
		else if (ft_strstr(line, "p2"))
		{
			filler->pid = 'x';
			ft_memdel((void**)&line);
			return (1);
		}
	}
	ft_memdel((void**)&line);
	return (0);
}

int		get_piece_size(char *line, char *kword, t_filler *filler)
{
	int i;

	filler->nmplins = 0;
	filler->nmpcols = 0;
	i = 0;
	if (ft_strstr(line, kword))
	{
		while (!ft_isdigit(line[i]))
			i++;
		filler->nmplins = ft_atoi(line + i);
		while (ft_isdigit(line[i]))
			i++;
		filler->nmpcols = ft_atoi(line + i);
		if (filler->nmplins && filler->nmpcols)
		{
			ft_memdel((void**)&line);
			return (1);
		}
	}
	ft_memdel((void**)&line);
	return (0);
}

int		get_board_size(char *line, char *kword, t_filler *filler)
{
	int i;

	filler->nmlines = 0;
	filler->nmcolumns = 0;
	i = 0;
	if (ft_strstr(line, kword))
	{
		while (!ft_isdigit(line[i]) && line[i] != '\0')
			i++;
		filler->nmlines = ft_atoi(line + i);
		while (ft_isdigit(line[i]) && line[i] != '\0')
			i++;
		filler->nmcolumns = ft_atoi(line + i);
		if (filler->nmcolumns && filler->nmlines)
		{
			ft_memdel((void**)&line);
			return (1);
		}
	}
	ft_memdel((void**)&line);
	return (0);
}

int		getter(t_filler *filler,\
		int (*gett)(char *line, char *strr, t_filler *filler), char *str)
{
	char	buff[2];
	char	*line;
	int		t[2];
	char	*strtmp;

	t[1] = 1;
	while ((t[0] = read(0, buff, 1)))
	{
		if (t[1] && !(line = (char*)ft_memalloc(1)))
			return (0);
		t[1] = 0;
		buff[1] = '\0';
		strtmp = ft_strjoin(line, buff);
		ft_memdel((void**)&line);
		if (!strtmp)
			return (0);
		line = strtmp;
		if (buff[0] == '\n' && (t[1] = 1))
			if (gett(line, str, filler))
				return (1);
	}
	if (line && gett(line, str, filler))
		return (1);
	return (0);
}
