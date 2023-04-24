/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 04:00:06 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/26 01:23:19 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	ft_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->input.n_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < info->input.n_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->msg_lock);
}

int	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	argument_is_clean(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (check_char(av[i]) == EXIT_FAILURE)
		{
			err_handl(5);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_input	input;
	t_info	*info;

	info = (t_info *) malloc(sizeof(t_info));
	if (ac == 5 || ac == 6)
	{
		av++;
		if (argument_is_clean(av) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (get_info(ac, av, &input))
			return (EXIT_FAILURE);
		if (check_info(&input, ac))
			return (EXIT_FAILURE);
		if (init_all(info, &input) == 0)
			ft_free(info);
	}
	else
		printf("Error: wrong the number of arguments\n");
	return (EXIT_SUCCESS);
}
