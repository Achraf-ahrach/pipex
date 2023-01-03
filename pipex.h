/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:51:40 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/02 15:51:58 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

char	*ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strjoin(char *s1, char *s2);
int     ft_strnstr(char **haystack, char *needle, size_t len);
char	**ft_split(char *s, char c);

#endif
