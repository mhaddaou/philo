/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:39:01 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/14 14:20:14 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int main (int ac, char **av)
{
    t_info    info;
    t_philo    philo;
    
    memset(&info, 0, sizeof(info));
    if (ac == 5 || ac == 6)
    {
        av++;
        parse(&info, ac, av);
        if (ac == 5)
            if (info.n_t_eat != 0)
                err_handl(1);
       check_input(&info, ac);
       create_filo(&info, &philo);
       create_forks(&philo);
       create_thread(&philo);
        
    }
    else
        err_handl(0);
    
}