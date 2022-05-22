/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:25:19 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/22 04:10:01 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"/

void    get_forks(t_philo *philo, int i, int g)
{
    philo->id = i + 1 ;
    philo->fork_left = g;
    philo->fork_right = i;
    philo->num_eat = 0;
}

void get_info(t_info *info)
{
    int i;
    int g;

    i = 1;
    g = 2;
    while (i < info->input.n_philo - 1)
    {
        get_forks(info->philo[i],i,g);
        printf("id == %d\n", id);
        g++;
        i++;
    }
    info->philo.should_die = 0;
}

int create_philo(t_info *info)
{
    get_info(info);
    return (EXIT_SUCCESS);
}