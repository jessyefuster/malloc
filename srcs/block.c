/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:32:54 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/30 17:11:38 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_block		*block_from_adress(void *adress)
{
	t_block		*block;

	block = (t_block *)adress;
	return (block);
}

void		delete_block_from_page(t_page *page, t_block *to_del)
{
	t_block		*ptr;

	ptr = page->blocks;
	if (ptr == to_del)
		page->blocks = NULL;
	else
	{
		while (ptr->next != to_del)
			ptr = ptr->next;
		ptr->next = to_del->next;
	}
}

void		add_block_to_page(t_page *page, t_block *new_block)
{
	void		*next_adress;
	int			between;
	t_block		*ptr;

	ptr = page->blocks;
	if (!ptr)
		page->blocks = new_block;
	else
	{
		while (ptr)
		{
			next_adress = ptr->next ? (void *)ptr->next : P_AFTER(page);
			between = (void *)ptr < (void *)new_block &&
						(void *)new_block < next_adress;
			if (between)
			{
				new_block->next = ptr->next;
				ptr->next = new_block;
			}
			ptr = ptr->next;
		}
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

t_block		*add_block(t_page *page, void *space, size_t block_size)
{
	t_block		*block;

	if (!page)
		return (NULL);
	block = block_from_adress(space);
	init_block(block, block_size);
	add_block_to_page(page, block);
	return (block);
}
