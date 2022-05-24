/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:38:21 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/24 00:29:41 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void get_input_to_info(t_info *info, t_input *input)
{
    info->input.n_philo = input->n_philo;
    info->input.t_die = input->t_die;
    info->input.t_eat = input->t_eat;
    info->input.t_sleep = input->t_sleep;
    info->input.last_meal = input->last_meal;
}

int init_mutex(t_info *info)
{
    int i;

    i = 0;
    if (pthread_mutex_init(&info->msg_lock, NULL))
        return(EXIT_FAILURE);
    while (i < info->input.n_philo)
    {
        if (pthread_mutex_init(&info->forks[i], NULL))
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
    
}


int init_all(t_info *info, t_input *input)
{
    get_input_to_info(info, input);
    info->philo = (t_philo *)malloc (sizeof(t_philo) * info->input.n_philo);
    info->forks = (pthread_mutex_t *)malloc (sizeof(pthread_mutex_t) * info->input.n_philo);
    if (!info->philo || !info->forks)
        return (EXIT_FAILURE);
    info->flag = 0;
    info->all_ate = 0;
    if (init_mutex(info))
        return (EXIT_FAILURE);
    if (create_philo(info))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}