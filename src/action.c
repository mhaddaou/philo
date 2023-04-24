/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:46:39 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/25 22:58:36 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	put_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->fork.left;
	right = philo->fork.right;
	pthread_mutex_unlock(&philo->info->forks[left]);
	pthread_mutex_unlock(&philo->info->forks[right]);
}

int	eat(t_philo *philo)
{
	long long	t;

	t = gettime();
	print_msg(philo, "is eating\n");
	while (gettime() - t < philo->info->input.t_eat)
		usleep(1);
	philo->last_meal = gettime();
	philo->info->eat++;
	if (philo->info->eat == philo->info->input.last_meal
		*philo->info->input.n_philo)
		philo->info->flag = 1;
	return (EXIT_SUCCESS);
}

int	take_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->fork.left;
	right = philo->fork.right;
	pthread_mutex_lock(&philo->info->forks[right]);
	print_msg(philo, "has taken a fork\n");
	if (philo->info->input.n_philo == 1)
	{
		uslep(philo->info->input.t_die);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(&philo->info->forks[left]);
	print_msg(philo, "has taken a fork\n");
	return (EXIT_SUCCESS);
}

void	*action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->info->input.n_philo != 1)
		if (philo->id % 2)
			usleep(700);
	while (!philo->should_die && !philo->info->flag)
	{
		if (take_forks(philo) == EXIT_FAILURE)
			break ;
		if (eat(philo) == EXIT_FAILURE)
			break ;
		put_forks(philo);
		sleep_then_think(philo);
		usleep(10);
	}
	return (NULL);
}
