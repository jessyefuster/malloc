/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 12:15:35 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/24 19:12:08 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*space_left(t_page *page, size_t block_size)
{
	void		*after_page;
	void		*after_last_block;
	t_block		*block;

	block = last_block(page->blocks);
	after_page = P_AFTER(page);
	after_last_block = B_AFTER(block);
	if (after_page - after_last_block >= (block_size + B_META_SIZE))
		return (after_last_block);
	return (NULL);
}

t_block		*search_free_block(size_t block_size)
{
	t_page		*page;

	page = first_page();
	while (page)
	{
		if (page->type == pagetype_from_block(block_size))
			if (space_left(page, block_size))
				return (add_block(page, block_size));
		page = page->next;
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
	block = add_block(page, block_size);
	return (block);
}

void		*my_malloc(size_t size)
{
	t_block		*new_block;

	new_block = search_free_block(size);
	if (!new_block)
		new_block = create_block(size, NULL);
	if (!new_block)
		return (NULL);
	return (B_DATA(new_block));
}
