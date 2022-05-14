/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:55:01 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/14 13:01:56 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void check_input(t_info *info, int ac)
{
    if (info->n_philo < 1)
        err_handl(2);
    if (info->t_die < 1)
        err_handl(3);
    if (info->t_eat < 1)
        err_handl(4);
    if (info->t_sleep < 1)
        err_handl(5);
    if (ac == 6)
        if (info->n_t_eat < 1)
            err_handl(6);
}