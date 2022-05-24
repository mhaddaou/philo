/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:25:19 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/24 03:38:54 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"


void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->info->forks[philo->])
    
    
}

void *action(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (!philo->should_die && !philo->info->flag)
    {
        take_forks(philo);
        
    }
    
    return (NULL);
}

long long gettime(void)
{
	t_time	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void get_forks(t_philo *philo, int i)
{
    
    philo->fork.left = i;
    philo->fork.right = i - 1;
}
void forks(t_philo *philo, int i, int j)
{
    if (i == 0)
    {
        philo->fork.left = i;
        philo->fork.right = j - 1;
    }
    else
    {
        philo->fork.left = i;
        philo->fork.right = i - 1;
    }
    
}

int create_philo(t_info *info)
{
     int i;
     pthread_t  thread;
    
    i = 0;
    info->start_time = gettime();     
    while (i < info->input.n_philo)
    {
        info->philo[i].id = i;
        info->philo[i].should_die = 0;
        info->philo[i].num_eat = 0;
        if (i > 0 && i < info->input.n_philo - 1)
            get_forks(&info->philo[i], i);
        if (i == 0 || i == info->input.n_philo - 1)
            forks(&info->philo[i], i, info->input.n_philo);
        info->philo[i].info = info;
        pthread_create(&info->philo[i].thread, NULL,&action,(void *)&info->philo[i]);
        pthread_create(&thread, NULL, &check_death, (void *)&info->philo[i]);
        pthread_join(info->philo->thread, NULL);
        
        i++;
    }
    
    return (EXIT_SUCCESS);
}