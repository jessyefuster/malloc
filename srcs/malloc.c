/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 12:15:35 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/23 15:18:41 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_block		*search_free_block(size_t block_size)
{
	t_page		*pages;

	pages = first_page();
	while (pages)
	{
		// IF SPACE AVAILABLE IN 
		pages = pages->next;
	}

	return (NULL);
}

t_block		*create_block(size_t block_size, t_page *page)
{
	t_block		*block;
	t_pagetype	pagesize;

	if (page == NULL)
	{
		pagesize = pagesize_from_block(block_size);
		page = create_page(pagesize);
	}

	block = add_block_in_page(page, block_size);

	return (block);
}

// void		*malloc(size_t size)
// {
// 	t_block		*new_block;

// 	new_block = search_free_block(size);
// 	if (!new_block)
// 		new_block = create_new_block(size);
// 	// if (!new_block)
// 	// 	return (NULL);
// 	// return (NULL);
// 	return (mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));
// }