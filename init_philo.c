/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:26:52 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/29 21:05:40 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_eat_check(t_philo_info *info)
{
	int	i;

	i = 0;
	info->eats = malloc(sizeof(pthread_mutex_t))
}

int	init_philo(t_philo_info *info)
{
	pthread_mutex_init(&(info->print), NULL);
	if (init_eat_check(info))
		return (1);
	
}
