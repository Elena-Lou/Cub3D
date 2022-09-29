/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:11:14 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/29 09:41:48 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*ft_skip_header(t_cub_data *data)
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
			else if ((map->line[i]) == '0' || map->line[i] == '1')
				return (list);
			i++;
		}
		list = list->next;
	}
	return (list);
}

int	ft_create_str(char **tab, int tab_size, int length)
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

int	ft_malloc_grid(t_list *list, char **tab, int tab_size)
{
	int			max_length;
	int			length;
	t_map_data	*map;
	int			i;

	i = 0;
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
	return (0);
}

int	ft_check_map_grid(t_cub_data *data)
{
	t_list		*list;
	int			tab_size;
	char		**tab;

	list = ft_skip_header(data);
	tab_size = ft_lstsize(list);
	tab = malloc(sizeof(*tab) * (tab_size + 1)); //secure malloc here
	if (tab == NULL)
		return (1); //clean exit here
	if (ft_malloc_grid(list, tab, tab_size) == WRONG_MALLOC)
		return (1); //clean exit here
	data->grid = tab;
	return (0);
}
