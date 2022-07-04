/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:54:52 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/07/04 15:55:11 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	philo_take_fork(philo);
}

int	philo_sleep(t_philo *philo)
{
	philo_print(philo, SLEEP);
	alt_sleep(philo->info->time_to_sleep);
	return (0);
}

int	philo_think(t_philo *philo)
{
	philo_print(philo, THINK);
	usleep(200);
	return (0);
}

void	philo_func(t_philo_info *info)
{
	t_philo	*philo;

	while (info->philo_dead == 0 && info->philo_eat == 0)
	{
		philo_eat(philo);
		if (info->philo_dead == 1)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
}
