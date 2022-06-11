/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:39:14 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/08 11:08:05 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

void	ft_init_2(t_state *aristo)
{
	int	i;

	i = 0;
	aristo->phi = malloc(sizeof(t_phi) * aristo->number_of);
	while (i < aristo->number_of)
	{
		aristo->phi[i].id = i;
		aristo->phi[i].count_eat = 0;
		aristo->phi[i].l_fork_id = i;
		aristo->phi[i].r_fork_id = (i + 1) % aristo->number_of;
		aristo->phi[i].link = aristo;
		aristo->phi[i].last_eat = gettime();
		i++;
	}
}

void	ft_init(t_state *aristo, int ac, char **av, int begin)
{
	int	len;

	aristo->number_of = ft_atoi(av[1]);
	aristo->time_to_die = ft_atoi(av[2]);
	aristo->time_to_eat = ft_atoi(av[3]);
	aristo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		aristo->must_eat = ft_atoi(av[5]);
	else
		aristo->must_eat = -1;
	len = aristo->number_of;
	begin = 0;
	aristo->died = false;
	aristo->eat_all = false;
	aristo->start_time = gettime();
	if (aristo->time_to_die < 60 || aristo->time_to_eat < 60
		|| aristo->number_of < 1 || aristo->time_to_sleep < 60)
		ft_exit("Error: THE time_to... CAN'T BE LESS THAN 60 ms");
	pthread_mutex_init(&aristo->random, NULL);
	aristo->fork_mutex = malloc(sizeof(pthread_mutex_t) * aristo->number_of);
	if (!aristo->fork_mutex)
		return ;
	while (begin < len)
		pthread_mutex_init(&aristo->fork_mutex[begin++], NULL);
	ft_init_2(aristo);
}
