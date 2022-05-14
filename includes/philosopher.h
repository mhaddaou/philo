/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:39:12 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/14 14:26:29 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
    int n_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int n_t_eat;
}   t_info;

typedef struct fork
{
    int left;
    int right;
}   t_fork;

typedef struct properties
{
    int id;
    int n_t_eat;
    int t_die;
    t_fork fork;
    pthread_t thread;
}   t_pro;

typedef struct philosopher
{
    int n_thread;
    int philo_dead;
    long long time_init;
    t_info info;
    t_pro *p_philo;
    pthread_mutex_t *forks;
    pthread_mutex_t mutex;

}   t_philo;

void parse(t_info *info, int ac, char **av);
int     ft_atoi(const char *str);
void err_handl (int x);
void ft_putstr_fd(char *s, int fd);
void check_input(t_info *info, int ac);
void create_filo(t_info *info, t_philo *philo);
void    create_forks(t_philo *philo);



#endif