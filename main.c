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

int		main(void)
{
	int i;
	char* addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
		// show_alloc_mem();
	}

	return (0);
}
// void	*ft_memset(void *dst, int c, size_t len)
// {
// 	size_t i = 0;

// 	while (i < len)
// 	{
// 		((unsigned char *)(dst))[i] = (unsigned char)c;
// 		i++;
// 	}

// 	return (dst);
// }


// int		main(void)
// {
// 	void	*addr1;
// 	void	*addr2;
// 	void	*addr3;
	


// 	addr1 = malloc(130);
// 	addr2 = malloc(130);
// 	addr3 = malloc(130);
// 	show_alloc_mem();

// 	// ft_putstr("\n\n");

// 	// addr2 = realloc(addr2, 126);
	
// 	// show_alloc_mem();
// 	// ft_putstr("\n\n");
	
// 	// free(addr2);
// 	// realloc(addr2, 130);
// 	// malloc(129);
	
// 	// show_alloc_mem();

// 	// ft_memset(addr1, '1', 10);
// 	// ft_memset(addr2, '2', 20);


// 	// int to_show = 2 * B_META_SIZE + 40;
// 	// for (int i = 0; i < to_show; i++)
// 	// {
// 	// 	write(1, addr1 - B_META_SIZE + 1 + i, 1);
// 	// 	write(1, "\n", 1);
// 	// }
// 	// ft_memset(addr2, '2', 20);

// 	// show_alloc_mem();


// 	return (0);
// }
