/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:09:37 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/23 15:31:21 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/malloc.h"


void	*my_malloc(size_t size)
{
	t_block		*new_block;

	new_block = search_free_block(size);
	if (!new_block)
		new_block = create_block(size, NULL);

	return (new_block);
}

int		main(void)
{
	t_page	*page;

	page = mmap(0, (sizeof(t_page) + 128), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	// block = (t_block *)P_DATA(page);

	void	*ptr;

	ptr = my_malloc(5);
	ptr = my_malloc(8);

	printf("%p\n", ptr);

	return (0);
}