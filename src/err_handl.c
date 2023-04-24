/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:06:01 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/26 00:44:59 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	err_handl(int err)
{
	if (err == 0)
		ft_putstr_fd("ERROR : Wrong number of philosophers\n", 2);
	if (err == 1)
		ft_putstr_fd("ERROR : Wrong number of time_to_eat\n", 2);
	if (err == 2)
		ft_putstr_fd("ERROR : Wrong number of time_to_die\n", 2);
	if (err == 3)
		ft_putstr_fd("ERROR : Wrong number of time_to_sleep\n", 2);
	if (err == 4)
		ft_putstr_fd("ERROR : Wrong num of must_eat\n", 2);
	if (err == 5)
		ft_putstr_fd("ERROR : Wrong arguments\n", 2);
}
