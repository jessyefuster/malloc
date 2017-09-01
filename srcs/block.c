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

t_block		*last_block(t_block *first)
{
	t_block		*ptr;

	ptr = first;
	if (!ptr)
		return (NULL);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

t_block		*block_from_adress(void *adress)
{
	t_block		*block;

	block = (t_block *)adress;
	return (block);
}

/*void		add_block_to_page(t_page *page, t_block *new_block)
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
}*/
void		add_block_to_page(t_page *page, t_block *new_block)
{
	t_block		*ptr;

	ptr = page->blocks;
	if (!ptr)
	{
		printf("first block add\n");
		page->blocks = new_block;
	}
	else
	{
		printf("else block add\n");
		while (ptr)
		{
			if (ptr->next)
			{
				if ((void *)ptr < (void *)new_block && (void *)new_block < (void *)ptr->next)
				{
					new_block->next = ptr->next;
					ptr->next = new_block;
				}
			}
			else
			{
				if ((void *)ptr < (void *)new_block && (void *)new_block < P_AFTER(page))
				{
					ptr->next = new_block;
				}
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
		block->free = 0;
		block->next = NULL;
	}
}

t_block		*add_block(t_page *page, void *space, size_t block_size)
{
	t_block		*block;
	// t_block		*ptr;

	if (!page)
		return (NULL);
	// ptr = page->blocks;
	// if (ptr)
	// {
	// 	// ptr = last_block(ptr);
	// 	block = block_from_adress(space);
	// }
	// else
	block = block_from_adress(space);
	printf("space %p\n", block);
	init_block(block, block_size);
	add_block_to_page(page, block);
	return (block);
}
