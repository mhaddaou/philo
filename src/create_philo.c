/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:25:19 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/24 00:56:30 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"


void    take_forks(t_philo *philo)
{
    
    int left = philo->fork.left;
    int right = philo->fork.right;
    pthread_mutex_lock(&philo->info->forks[left]);
    print_msg(philo,"has taken a fork\n");
    pthread_mutex_lock(&philo->info->forks[right]);
    print_msg(philo, "has taken a fork\n");
}

void    put_forks(t_philo *philo)
{
    int left;
    int right;

    left = philo->fork.left;
    right = philo->fork.right;
    pthread_mutex_unlock(&philo->info->forks[left]);
    pthread_mutex_unlock(&philo->info->forks[right]);
}

void eat(t_philo *philo)
{
    print_msg(philo, "is eating\n");
    uslep(philo->info->input.t_eat);
    philo->last_meal = gettime();
    philo->num_eat++;
    if (philo->num_eat == philo->info->input.last_meal)
        philo->info->all_ate++;
}

void    sleep_then_think(t_philo *philo)
{
    print_msg(philo,"is sleeping\n");
    uslep(philo->info->input.t_sleep);
    print_msg(philo, "is thinking\n");
}

void *action(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (!philo->should_die && !philo->info->flag)
    {
        take_forks(philo);
        put_forks(philo);
        eat(philo);
        sleep_then_think(philo);
        usleep(10);
    }
    
    return (NULL);
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
        info->n_thread = i;
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