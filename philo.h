/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:58:38 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/07/04 15:36:21 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4
# define FORK_L 5
# define FORK_R 6

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo_info	t_philo_info;

typedef struct s_philo{
	int				number;
	long long		fed_time;
	int				eat_cnt;
	pthread_t		thread;
	pthread_mutex_t	*print;
	pthread_mutex_t	*deadcheck;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_philo_info	*info;
}	t_philo;
/*철학자 하나하나 */

typedef struct s_philo_info{
	t_philo			*philo_args;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				finish_line;
	long long		time_of_start;
	int				philo_dead;
	int				philo_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	*deadcheck;
	pthread_mutex_t	*forks;
}	t_philo_info;
/*철학자들 총괄*/

int		init_arg(int ac, char **av, t_philo_info *info);
int		print_err(char *str);
int		ft_atoi(const char *str);

int		get_time(void);
void	alt_sleep(long long time_to_sleep);

int		init_philo(t_philo_info *info);
void	philo_print(t_philo *philo, int state);
#endif