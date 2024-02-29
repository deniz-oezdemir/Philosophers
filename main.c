/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:11:18 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/22 14:45:42 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	main(int ac, char **av)
{
	t_data	*dat;

	dat = 0;
	if (ac == 5 || ac == 6)
	{
		dat = (t_data *)malloc(sizeof(t_data));
		if (init_all(dat, ac, av))
			return (1);
	}
	else
		return (error(dat, "Invalid number of arguments"));
	if (dat->nbr_phils == 1)
		return (one_phil(dat));
	else if (mlt_phils(dat))
		return (1);
	clean(dat);
	return (0);
}
