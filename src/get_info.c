/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 04:19:53 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/25 23:11:23 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	get_info(int ac, char **av, t_input *info)
{
	memset(info, 0, sizeof(*info));
	info->n_philo = ft_atoi(av[0]);
	info->t_die = ft_atoi(av[1]);
	info->t_eat = ft_atoi(av[2]);
	info->t_sleep = ft_atoi(av[3]);
	info->ac = ac;
	if (ac == 6)
		info->last_meal = ft_atoi(av[4]);
	return (EXIT_SUCCESS);
}
