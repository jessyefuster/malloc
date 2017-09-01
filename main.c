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
// 	char* addr;

// 	i = 0;
// 	while (i < 1024)
// 	{
// 		addr = (char*)my_malloc(1024);
// 		addr[0] = 42;
// 		my_free(addr);
// 		i++;
// 		// show_alloc_mem();
// 	}

// 	return (0);
// }
void	*ft_memset(void *dst, int c, size_t len)
{
	int i = 0;

	while (i < len)
	{
		((unsigned char *)(dst))[i] = (unsigned char)c;
		i++;
	}

	return (dst);
}


int		main(void)
{
	void	*addr1;
	void	*addr2;
	void	*addr3;

	addr1 = my_malloc(130);
	addr2 = my_malloc(130);
	addr3 = my_malloc(130);

	show_alloc_mem();
	printf("\n\n");
	my_realloc(addr2, 128);
	show_alloc_mem();
	printf("\n\n");
	// my_free(addr4);
	// printf("%p\n", my_realloc(addr4, 130));
	my_malloc(129);
	show_alloc_mem();

	// ft_memset(addr1, '1', 10);
	// ft_memset(addr2, '2', 20);


	// int to_show = 2 * B_META_SIZE + 40;
	// for (int i = 0; i < to_show; i++)
	// {
	// 	write(1, addr1 - B_META_SIZE + 1 + i, 1);
	// 	write(1, "\n", 1);
	// }
	// ft_memset(addr2, '2', 20);

	// show_alloc_mem();


	return (0);
}
