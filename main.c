/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:09:37 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/23 18:38:32 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/malloc.h"

char	*pagetype_str(t_pagetype type)
{
	if (type == TINY)
		return ("TINY");
	else if (type == SMALL)
		return ("SMALL");
	else
		return ("LARGE");
}

void	show_alloc_mem(void)
{
	size_t	total = 0;
	t_page	*page;
	t_block	*block;

	page = first_page();
	while (page)
	{
		printf("%s : %p\n", pagetype_str(page->type), P_DATA(page));
		block = page->blocks;
		while (block)
		{
			printf("%p - %p : %zu octets\n", B_DATA(block), B_DATA(block) + block->size - 1, block->size);
			total += block->size;
			block = block->next;
			// printf("\n");
		}
		page = page->next;
	}
	printf("Total : %zu octets\n", total);
}

void	*my_malloc(size_t size)
{
	t_block		*new_block;

	new_block = search_free_block(size);
	if (!new_block)
		new_block = create_block(size, NULL);
	if (!new_block)
		return (NULL);

	return (B_DATA(new_block));
}

int		main(void)
{
	t_page	*page;

	page = mmap(0, (sizeof(t_page) + 128), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	// block = (t_block *)P_DATA(page);

	void	*ptr;

	my_malloc(5);
	my_malloc(8);
	my_malloc(200);
	my_malloc(2000);

	show_alloc_mem();
	// printf("%p\n", ptr);
	// printf("%zu\n", sizeof(int*));

	return (0);
}