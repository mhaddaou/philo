/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:59:38 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/24 00:55:09 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"


void    *check_death(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (!philo->info->flag)
    {
        if ((philo->last_meal + philo->info->input.t_die) < gettime())
        {
            print_msg(philo,"died\n");
            philo->should_die = 1;
            philo->info->flag = 1;
        }
        
    }
    
    
    return (NULL);
    
}