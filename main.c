/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:09:37 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/22 18:49:35 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/malloc.h"


void	*my_malloc(size_t size) {
	t_block		*new_block;

	new_block = search_free_block(size);
	if (!new_block)
		new_block = create_new_block(size);
	if (!new_block)
		return (NULL);

	return (new_block);
}

int		main(void)
{
	char *ptr;
	ptr = (char*)my_malloc(9);

	t_page *page = mmap(0, (sizeof(t_page) + 128), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);


	printf("medata adress: %p\n", page);
	printf("page adress:   %p\n\n", (void *)page + sizeof(t_page) );

	printf("adress difference:    %ld\n", (page + sizeof(t_page)) - page);

	printf("medata len:    %lu -> type : %lu, \n", sizeof(t_page), sizeof(page->type));


	return (0);
}