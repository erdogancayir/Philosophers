/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:53:01 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/11 15:53:02 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "semaphore.h"
# include "pthread.h"
# include "stdint.h"
# include "sys/time.h"
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/stat.h> 
# include "stdbool.h"
# include "sys/time.h"
# include "sys/wait.h"
# include <signal.h>

typedef struct s_env	t_state;

typedef struct s_a
{
	int			pid;
	int			id;
	int			eat_count;
	uint64_t	last_eat;
	t_state		*link;
}				t_phis;

typedef struct s_env
{
	int			number_of;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			must_eat;
	uint64_t	start_time;
	sem_t		*forks;
	sem_t		*print;
	bool		all_eat;
	bool		is_died;
	pthread_t	yep;
	pthread_t	check;
	t_phis		*philo;
}				t_state;

uint64_t	gettime(void);
void		ft_exit(char *s);
int			ft_atoi(char *s);
void		*waitp(void *data);
void		process(t_state *all);
void		meal_time(t_phis *philo);
void		philo_think(t_phis *philo);
void		philo_sleep(t_phis *philo);
void		pass_the_time(int time, t_state *all);
void		print(int id, char *s, t_state *aristo);
void		init_arguments(t_state *all, int ac, char **av);
#endif
