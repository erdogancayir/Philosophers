/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:36:27 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/08 11:14:10 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

void	die(t_state *aristo, int i, int j)
{
	while (aristo->eat_all == false)
	{
		i = 0;
		while (i < aristo->number_of)
		{
			if (gettime() - aristo->phi[i].last_eat > aristo->time_to_die)
			{
				print(aristo->phi[i].id, "\033[0;91mPhilosop died", aristo);
				aristo->died = true;
				if (aristo->number_of == 1)
				{
					pthread_mutex_destroy(&aristo->random);
					while (++j < aristo->number_of)
						pthread_mutex_destroy(&aristo->fork_mutex[j]);
					pthread_mutex_destroy(&aristo->random);
					exit(0);
				}
			}
			i++;
		}
		if (aristo->died == true)
			break ;
	}
}
