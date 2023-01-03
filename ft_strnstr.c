/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:01:11 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/02 15:54:41 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_strnstr(char **haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (haystack[i])
	{
        j = 0; 
        if (haystack[i][j] == needle[j])
        {
            while (haystack[i][j] == needle[j])
                j++;
            if (j == len)
                return (i);
        }
		i++;
	}
	return (-1);
}
