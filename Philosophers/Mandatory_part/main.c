/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:58:26 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/05 10:59:00 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

int	main(int ac, char **av)
{
	t_state	*aristo;

	aristo = malloc(sizeof(t_state));
	if (!aristo)
		return (0);
	if (ac != 5 && ac != 6)
		ft_exit("Bad number of arg...");
	ft_init(aristo, ac, av, 0);
	create_thread(aristo, -1, -1);
}
