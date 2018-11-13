/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyefuster <jessyefuster@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 12:15:35 by jfuster           #+#    #+#             */
/*   Updated: 2018/11/13 17:21:31 by jessyefuster     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_block		*search_free_block(size_t block_size)
{
	void		*space;
	t_page		*page;

	page = first_page();
	while (page)
	{
		if (page->type == pagetype_from_block(block_size))
		{
			if ((space = space_left(page, block_size + B_META_SIZE)))
				return (add_block(page, space, block_size));
		}
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
	block = add_block(page, P_DATA(page), block_size);
	return (block);
}

void		*malloc(size_t size)
{
	t_block		*new_block;

	new_block = search_free_block(size);
	if (pagetype_from_block(size) == LARGE || !new_block)
		new_block = create_block(size, NULL);
	if (!new_block)
		return (NULL);
	return (B_DATA(new_block));
}
