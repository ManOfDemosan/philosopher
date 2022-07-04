/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:26:48 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/07/04 21:58:34 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, int state)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d ", get_time() - philo->info->time_of_start, philo->number);
	if (state == EAT)
	{
		printf("is eating");
		if (philo->info->finish_line)
			printf(" - have eaten %d times", philo->eat_cnt);
		printf("\n");
	}
	else if (state == SLEEP)
		printf("is sleeping\n");
	else if (state == THINK)
		printf("is thinking\n");
	else if (state == FORK_L)
		printf("has taken fork on the left\n");
	else if (state == FORK_R)
		printf("has taken fork on the right\n");
	else if (state == DEAD)
	{
		printf("died\n");
		return ;
	}
	pthread_mutex_unlock(philo->print);
}

void	philo_take_fork(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo_print(philo, FORK_L);
		pthread_mutex_lock(philo->right_fork);
		philo_print(philo, FORK_R);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo_print(philo, FORK_R);
		pthread_mutex_lock(philo->left_fork);
		philo_print(philo, FORK_L);
	}
}
