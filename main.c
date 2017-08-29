/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:09:37 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/29 17:36:54 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

int		main(void)
{
	void	*addr;

	my_malloc(5);
	my_malloc(4);

	my_malloc(200);

	addr = my_malloc(2000);

	show_alloc_mem();

	my_free(addr);

	ft_putstr("\n\n");
	show_alloc_mem();
	return (0);
}