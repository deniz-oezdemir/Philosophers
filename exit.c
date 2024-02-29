/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:20:50 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/24 15:59:51 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	error(t_data *dat, char *msg)
{
	if (dat)
	{
		if (dat->tids)
			free(dat->tids);
		if (dat->frks)
			free(dat->frks);
		if (dat->phils)
			free(dat->phils);
		free(dat);
	}
	printf("Error: %s\n", msg);
	return (1);
}

void	clean(t_data *dat)
{
	int	i;

	pthread_mutex_destroy(&dat->m_dth);
	pthread_mutex_destroy(&dat->m_print);
	i = 0;
	while (i < dat->nbr_phils)
	{
		pthread_mutex_destroy(&dat->frks[i]);
		pthread_mutex_destroy(&dat->phils[i].m_eating);
		i++;
	}
	if (dat->tids)
		free(dat->tids);
	if (dat->frks)
		free(dat->frks);
	if (dat->phils)
		free(dat->phils);
	if (dat)
		free(dat);
}
