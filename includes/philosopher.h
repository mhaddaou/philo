/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 04:00:25 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/23 14:48:21 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>





typedef struct input
{
    int n_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int last_meal; 
}   t_input;
typedef struct forks
{
    int left;
    int right;
}   t_forks;

typedef struct philo
{
    int id;
    int num_eat;
    int should_die;
    long long last_meal;
    t_forks fork;
    t_info *info;
    pthread_t thread;
}   t_philo;

typedef struct info
{
	int				flag;
	int				all_ate;
	long long		start_time;
    t_input         input;
	t_philo			*philo;
   	
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg_lock;
}	t_info;

int get_info(int ac, char **av, t_input *info);
int	ft_atoi(const char *str);
void err_handl (int err);
void ft_putstr_fd(char *str, int fd);
int check_info(t_input *info, int ac);
int init_mutex(t_info *info);
int init_all(t_info *info, t_input *input);
void get_input_to_info(t_info *info, t_input *input);
int create_philo(t_info *info);
void get_pro(t_info *info);

#endif