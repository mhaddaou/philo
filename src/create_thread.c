/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:20:31 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/15 15:36:42 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void    philo_eat(t_philo *philo, int t)
{
    pthread_mutex_lock(&philo->forks[philo->p_philo[t].fork.left]);
    printf("%d get up fork\n", t);
    pthread_mutex_lock(&philo->forks[philo->p_philo[t].fork.right]);
    pthread_mutex_unlock(&philo->forks[philo->p_philo[t].fork.left]);
    pthread_mutex_unlock(&philo->forks[philo->p_philo[t].fork.right]);
}

void routine_execute(t_philo *philo, int t)
{
    philo_eat(philo, t);
}

void    *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *) arg;

    int t = philo->n_thread;
    routine_execute(philo, t);
    
    return NULL;
}


void    create_thread(t_philo *philo)
{
    int i;

    i = 0;
    pthread_mutex_init (&philo->mutex, NULL);
    while (i < philo->info.n_philo)
    {
        // printf("im here\n");
        philo->n_thread = i;
        pthread_create(&philo->p_philo[i].thread,NULL, &routine, (void *) philo );
        i++;
        usleep(500);
    }
    i = 0;
    while (i< philo->info.n_philo)
    {
        pthread_join(philo->p_philo[i].thread, NULL);
        i++;
    }
}