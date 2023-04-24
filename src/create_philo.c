/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:25:19 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/25 23:08:25 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	sleep_then_think(t_philo *philo)
{
	long long	t;

	print_msg(philo, "is sleeping\n");
	t = gettime();
	while (gettime() - t < philo->info->input.t_sleep)
		usleep(1);
	print_msg(philo, "is thinking\n");
}

void	get_forks(t_philo *philo, int i)
{
	philo->fork.left = i;
	philo->fork.right = i - 1;
}

void	forks(t_philo *philo, int i, int j)
{
	if (i == 0)
	{
		philo->fork.left = i;
		philo->fork.right = j - 1;
	}
	else
	{
		philo->fork.left = i;
		philo->fork.right = i - 1;
	}
}

void	create_philo(t_info *info)
{
	int			i;
	pthread_t	thread;

	i = 0;
	info->start_time = gettime();
	while (i < info->input.n_philo)
	{
		info->philo[i].id = i;
		info->philo[i].should_die = 0;
		info->philo[i].num_eat = 0;
		info->philo[i].last_meal = info->start_time;
		if (i > 0 && i < info->input.n_philo - 1)
			get_forks(&info->philo[i], i);
		if (i == 0 || i == info->input.n_philo - 1)
			forks(&info->philo[i], i, info->input.n_philo);
		info->philo[i].info = info;
		pthread_create (&info->philo[i].thread, NULL,
			&action, (void *) &info->philo[i]);
		pthread_create (&thread, NULL, &check_death, (void *)&info->philo[i]);
		pthread_detach (thread);
		usleep(40);
		i++;
	}	
}
