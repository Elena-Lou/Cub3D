/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:11:14 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 19:43:45 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_list	*ft_skip_header(t_cub_data *data)
{
	t_map_data	*map;
	t_list		*list;
	int			i;

	list = data->lst_map;
	while (list)
	{
		map = (t_map_data *)list->content;
		i = 0;
		while (map->line && map->line[i])
		{
			if (ft_iswhitespace(map->line[i]))
				i++;
			else if (ft_isalpha(map->line[i]))
				break ;
			else if ((map->line[i]) == '0' || map->line[i] == '1')
				return (list);
		}
		list = list->next;
	}
	return (list);
}

static int	ft_create_str(char **tab, int tab_size, int length)
{
	int	i;

	i = 0;
	while (i < tab_size)
	{
		tab[i] = malloc(sizeof(*tab[i]) * (length + 1));
		if (tab[i] == NULL)
		{
			while (--i >= 0)
			{
				free(tab[i]);
				return (1);
			}
		}
		i++;
	}
	tab[i] = NULL;
	return (0);
}

static void	ft_fill_grid(t_list *list, int length)
{
	t_map_data	*map;
	t_cub_data	*data;
	int			i;
	int			j;

	map = (t_map_data *)list->content;
	data = map->data;
	i = 0;
	while (list)
	{
		map = (t_map_data *)list->content;
		j = -1;
		while (map->line[++j])
			data->grid[i][j] = map->line[j];
		while (j < length)
		{
			data->grid[i][j] = '\0';
			j++;
		}
		data->grid[i][j] = '\0';
		i++;
		list = list->next;
	}
}

int	ft_malloc_grid(t_list *list, t_list *start, char **tab, int tab_size)
{
	int			max_length;
	int			length;
	t_map_data	*map;

	max_length = 0;
	while (list)
	{
		map = (t_map_data *) list->content;
		length = ft_strlen_int(map->line);
		if (length > max_length)
			max_length = length;
		map = list->content;
		list = list->next;
	}
	if (ft_create_str(tab, tab_size, max_length) == 1)
		return (WRONG_MALLOC);
	ft_fill_grid(start, max_length);
	return (0);
}

int	ft_create_map_grid(t_cub_data *data)
{
	t_list		*list;
	int			tab_size;
	char		**tab;

	list = ft_skip_header(data);
	tab_size = ft_lstsize(list);
	tab = malloc(sizeof(*tab) * (tab_size + 1));
	if (tab == NULL)
		return (ft_wrong_map_exit(data->lst_map, "Malloc: ", "Error"), 1);
	data->grid = tab;
	if (ft_malloc_grid(list, list, tab, tab_size) == WRONG_MALLOC)
		return (ft_wrong_map_exit(data->lst_map, "Malloc: ", "Error"), 1);
	data->grid = tab;
	return (0);
}
