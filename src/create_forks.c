/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:15:07 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/14 14:18:26 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void    create_forks(t_philo *philo)
{
    philo->forks = malloc (sizeof(pthread_mutex_t) * philo->info.n_philo + 1);
    int i = 0;
    
    while (i < philo->info.n_philo)
    {
        if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
            err_handl(10);
        i++;
    }
}