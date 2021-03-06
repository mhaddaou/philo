/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 04:00:06 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/23 22:50:27 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"


int main (int ac, char **av)
{
    t_input input;
    t_info info;
    
    if (ac ==  5 || ac == 6)
    {
        
        av++;
        if (get_info(ac, av, &input))
            return (EXIT_FAILURE);
        if (check_info(&input, ac))
            return (EXIT_FAILURE);
        init_all(&info, &input);
    }
    else
        printf("Error: wrong the number of arguments\n");
    
    return (EXIT_SUCCESS);
}