/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:45:48 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/11 15:50:27 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int ac, char **av)
{
	t_state	*all;

	all = (t_state *)malloc(sizeof(t_state));
	if (ac != 5 && ac != 6)
		ft_exit("Bad number of arguman");
	init_arguments(all, ac, av);
	process(all);
}
