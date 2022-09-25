/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strptr_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:20:26 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/22 14:05:14 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strptr_to_str(char **strptr)
{
	char	*tmp;

	if (strptr == NULL || *strptr == NULL)
		return (NULL);
	if (*strptr && *(strptr + 1))
	{
		tmp = ft_strjoin(*strptr, *(strptr + 1));
		strptr += 2;
	}
	else
		return (ft_strdup(*strptr));
	while (*strptr)
	{
		tmp = ft_strjoin_free(tmp, *strptr);
		strptr++;
	}
	return (tmp);
}
