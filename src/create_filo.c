/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_filo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:04:22 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/14 20:41:28 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"


void    get_data(t_philo *philo, int i, int j, int g)
{
    philo->p_philo[i].id = j;
    philo->p_philo[i].n_t_eat = 0;
    philo->p_philo[i].t_die = 0;
    philo->p_philo[i].fork.left = g;
    philo->p_philo[i].fork.right = j;
}

void    fix_data(t_philo *philo)
{
    philo->p_philo[0].id = 1;
    philo->p_philo[0].n_t_eat = 0;
    philo->p_philo[0].t_die = 0;
    philo->p_philo[0].fork.left = 1;
    philo->p_philo[0].fork.right = philo->info.n_philo;
    
    
    philo->p_philo[philo->info.n_philo - 1].id = philo->info.n_philo;
    philo->p_philo[philo->info.n_philo - 1].n_t_eat = 0;
    philo->p_philo[philo->info.n_philo - 1].t_die = 0;
    philo->p_philo[philo->info.n_philo - 1].fork.left = philo->info.n_philo;
    philo->p_philo[philo->info.n_philo - 1].fork.right = philo->info.n_philo - 1;
}

void create_filo(t_info *info, t_philo *philo)
{
    int i;
    int j;
    int g;
    philo->info = *info;
    philo->p_philo = malloc (sizeof(t_philo) * (info->n_philo + 1));
    i = 1;
    j = 1;
    g = 2;
    while (i < info->n_philo - 1)
    {
        get_data(philo, i, j, g);
        i++;
        j++;
        g++;
    }
    fix_data(philo);
}
