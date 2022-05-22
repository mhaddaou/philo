/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:01:59 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/22 01:18:29 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int check_info(t_input *info, int ac)
{
    if (info->n_philo < 1)
    {
        err_handl(0);
        return (EXIT_FAILURE);
    }
    if (info->t_eat < 60)
    {
        err_handl(1);
        return (EXIT_FAILURE);
    }
    if (info->t_die < 60)
    {
        err_handl(2);
        return (EXIT_FAILURE);
    }
    if (info->t_sleep < 60)
    {
        err_handl(3);
        return (EXIT_FAILURE);
    }
    if (ac == 6 && info->last_meal == 0)
    {
        err_handl(4);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}