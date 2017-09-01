/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:09:37 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/31 12:19:00 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

// int		main(void)
// {
// 	int i;

// 	i = 0;
// 	while (i < 1024)
// 	{
// 		addr = (char*)my_malloc(1024);
// 		addr[0] = 42;
// 		my_free(addr);
// 		// show_alloc_mem();
// 		i++;
// 	}

// 	return (0);
// }


int		main(void)
{
	void	*addr1;
	void	*addr2;
	void	*addr3;

	addr1 = my_malloc(10);
	addr2 = my_malloc(20);
	// addr3 = my_malloc(10);

	show_alloc_mem();
/*	printf("\n\n");
	void *addr4 = my_realloc(addr2, 5);
	show_alloc_mem();
	printf("\n\n");
	my_free(addr4);
	printf("%p\n", my_realloc(addr2, 12));
	show_alloc_mem();*/


	return (0);
}
