/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:14:16 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/25 23:19:26 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

long long	gettime(void)
{
	t_time	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long long	current_time(t_philo *philo)
{
	long long	time;

	time = gettime() - philo->info->start_time;
	return (time);
}

void	uslep(int time)
{
	long long	t;
	long long	time2;

	time2 = time;
	t = gettime();
	while (gettime() - t < time2)
		usleep (1);
}
