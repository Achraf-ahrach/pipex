/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 08:30:47 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/01 16:09:44 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *ft_check(char **p, char *comand) 
{
    int i;
    int j;
    char *path;
    
    j = 0;
    i = -1;
    while (i != 0 && p[j] != NULL)
    {
        path = ft_strjoin(p[j], comand);
        i = access(path, F_OK);
        if (i == -1)
            free(path);
        j++;
    }
    if (i == 0)
       return (path);
    return(NULL);
}

void    ft_child1(char **av, char **env, int *pi, int i)
{
    char **p;
    int fd;
    char **cm;
    char *comand;
    
    if (i != -1)
    {
        p = ft_split(env[i]+5, ':');
        if (p != NULL)
        {
            cm = ft_split(av[2], ' ');
            comand = ft_check(p, cm[0]);
            if (comand != NULL)
            {
                fd = open(av[1], O_RDONLY);
                dup2(pi[1], 1);
                dup2(fd, 0);
                execve(comand, cm, NULL);
            }
        }
    }
    perror("error");
}

void ft_child2(char **av, char **env, int *pi, int i)
{
    char **p;
    char *comand;
    char **cm;
    int fd;
    
    if (i != -1)
    {
        p = ft_split(env[i]+5, ':');
        //system("leaks pipex");
        if (p != NULL)
        {
            cm = ft_split(av[3], ' ');
            comand = ft_check(p, cm[0]);
            if (comand != NULL)
            {
                fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC , 0777);
                dup2(pi[0], 0);
                dup2(fd, 1);
                close(pi[1]);
                execve(comand, cm, NULL);
            }
        }
    }
    perror("error");
}

int main(int ac, char **av, char **env)
{
    int pi[2];
    int i;
    
    if (ac != 5)
    {
        write(1, "machi 5 dyal arguments !", 24);
        exit(0);
    }
    pipe(pi);
    if (fork() != 0)
    {
        if (fork() == 0)
        {
            i = ft_strnstr(env, "PATH=");
            ft_child2(av, env, pi, i);
        }
    }
    else
    {
        i = ft_strnstr(env, "PATH=");
        ft_child1(av, env, pi, i);
    }
    close(pi[0]);
    close(pi[1]);
    wait(NULL);
    wait(NULL);
}