/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:20:31 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/14 14:29:09 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void    create_thread(t_philo *philo)
{
    pthread_mutex_init (&philo->mutex);
    while (i < philo->info.n_philo)
    {
        philo->n_thread = 1;
        pthread_create(&philo->p_philo[i].thread, )
    }
    
}