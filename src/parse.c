/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:45:56 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/14 12:46:55 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void parse(t_info *info, int ac, char **av)
{
    info->n_philo = ft_atoi(av[0]);
    info->t_die = ft_atoi(av[1]);
    info->t_eat = ft_atoi(av[2]);
    info->t_sleep = ft_atoi(av[3]);
    if (ac == 6)
        info->n_t_eat = ft_atoi(av[4]);
}