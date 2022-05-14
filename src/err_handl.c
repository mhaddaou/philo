/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:51:52 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/14 14:18:08 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void err_handl (int x)
{
   if (x == 0)
      ft_putstr_fd("argument is not valide", 2);
   if (x == 1)
      ft_putstr_fd("Error\n", 2);
   if (x == 2)
      ft_putstr_fd("Error : the number of philosopher is incorect", 2);   
   if (x == 3)
      ft_putstr_fd("Error : the number of die is incorect", 2);
   if (x == 4)
      ft_putstr_fd("Error : the number of eat is incorect", 2);
   if (x == 5)
      ft_putstr_fd("Error : the number of sleep is incorect", 2);
   if (x == 6)
      ft_putstr_fd("Error : the number of number_of_times_each_philosopher_must_eat is incorect", 2);
   if(x == 9)
      printf("error in forks");
   if (x == 10)
      printf("error probleme init mutex");
   
    

   exit(EXIT_SUCCESS);
}