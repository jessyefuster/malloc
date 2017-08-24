/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:32:54 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/24 18:08:37 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_block		*last_block(t_block *first)
{
	t_block		*ptr;

	ptr = first;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

t_block		*add_block_in_mem(void *adress)
{
	t_block		*block;

	block = (t_block *)adress;
	return (block);
}

void		add_block_to_page(t_page *page, t_block *new_block)
{
	t_block		*ptr;

	ptr = page->blocks;
	if (!ptr)
		page->blocks = new_block;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_block;
	}
	page->busy += B_META_SIZE + new_block->size;
}

void		init_block(t_block *block, size_t block_size)
{
	if (block)
	{
		block->size = block_size;
		block->next = NULL;
	}
}

t_block		*add_block(t_page *page, size_t block_size)
{
	t_block		*block;
	t_block		*ptr;

	if (!page)
		return (NULL);
	ptr = page->blocks;
	if (ptr)
	{
		ptr = last_block(ptr);
		block = add_block_in_mem((B_AFTER(ptr)));
	}
	else
		block = add_block_in_mem(P_DATA(page));
	init_block(block, block_size);
	add_block_to_page(page, block);
	return (block);
}
