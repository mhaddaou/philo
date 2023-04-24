/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:05:23 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/25 23:20:38 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

static int	rond_prevent(int c)
{
	if (c < 0)
		return (0);
	else
		return (-1);
}

static int	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == ' '
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	g;
	int	result;

	i = 0;
	g = 1;
	result = 0;
	while (ft_isspace(((char *)str)[i]))
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
		{
			g *= -1;
		}
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (i > 19)
		return (rond_prevent(g));
	return (result * g);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->msg_lock);
	if (!philo->info->flag)
		printf("%lli\t%i %s", current_time(philo), philo->id + 1, msg);
	pthread_mutex_unlock(&philo->info->msg_lock);
}
