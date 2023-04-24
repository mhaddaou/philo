/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:30:28 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/05/26 01:09:16 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	check_info2(t_input *info, int ac)
{
	if (info->t_sleep < 60)
	{
		err_handl(3);
		return (EXIT_FAILURE);
	}
	if (ac == 6 && info->last_meal == 0)
	{
		err_handl(4);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
