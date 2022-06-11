/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:45:07 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/08 17:18:22 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHI_H
# define PHI_H

# include <stdio.h>
# include "unistd.h"
# include "stdlib.h"
# include "pthread.h"
# include "stdbool.h"
# include "sys/time.h"

struct	s_state;

typedef struct s_phi
{
	int				id;
	int				r_fork_id;
	int				l_fork_id;
	int				count_eat;
	uint64_t		last_eat;
	pthread_t		th_id;
	struct s_state	*link;
}t_phi;

typedef struct s_state
{
	int				number_of;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;	
	bool			died;
	bool			eat_all;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	random;
	t_phi			*phi;
	uint64_t		start_time;
}t_state;

int			ft_atoi(char *s);
void		ft_init(t_state *aristo, int ac, char **av, int begin);
void		ft_exit(char *s);
uint64_t	gettime(void);
void		create_thread(t_state *aristo, int i, int j);
void		print(int id, char *s, t_state *aristo);
void		put_on_hold(int time, t_state *aristo);
void		die(t_state *aristo, int i, int j);
void		pass_the_time(int time, t_state *aristo);

#endif
