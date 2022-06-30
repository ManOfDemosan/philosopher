/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:58:38 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/30 13:23:59 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
typedef struct s_philo_info	t_philo_info;

typedef struct s_philo{
	int				thread_num;
	pthread_t		id;
	t_philo_info	*info;
}	t_philo;
/*철학자 하나하나 */

typedef struct s_philo_info{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			finish_line;
	int			time_of_start;	
}	t_philo_info;
/*철학자들 총괄*/

int	init_arg(int ac, char **av, t_philo_info *info);
int	print_err(char *str);
int	ft_atoi(const char *str);
int	get_time(void);
int	init_philo(t_philo_info *info);
#endif