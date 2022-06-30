/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:05:55 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/30 13:46:02 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int ac, char **av)
{	
	t_philo_info	info;

	if (ac < 5 || ac > 6)
		return (print_err("Error: argument\n"));
	if (init_arg(ac, av, &info) != 0)
		return (1);
	else
		printf("SUCESS!\n");
	//init_philo(&info);
	return (0);
}

// void	*t_putstr(void *arg)
// {
	
// 	printf("hello\n");
// 	return (NULL);
// }

// int	main(int ac, char **av)
// {
// 	pthread_t philo[5];

// 	for(int i = 0; i < 5; i++)
// 	{
// 		pthread_create(&(philo[i]), NULL, t_putstr, NULL);
// 		pthread_join(philo[i], NULL);
// 	}
// }