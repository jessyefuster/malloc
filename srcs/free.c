/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 12:11:07 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/29 17:34:59 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_page		*page_from_block(t_block *block)
{
	t_page	*pages;

	pages = first_page();
	while (pages)
	{
		if ((void *)pages < (void *)block && P_AFTER(pages) > (void *)block)
			return (pages);
		pages = pages->next;
	}
	return (NULL);
}

void		clean_page(t_page *page)
{
	size_t		unmap_size;
	t_block		*block;

	block = page->blocks;
	while (block)
	{
		if (block->free == 0)
			return ;
		block = block->next;
	}
	ft_putstr("UNMAPPING\n");
	delete_page(page);
	unmap_size = page->size;
	if (pagetype_from_pagesize(page->size) == LARGE)
		unmap_size += P_META_SIZE + B_META_SIZE;
	munmap((void *)page, unmap_size);
}


void		free_block(t_block *block)
{
	block->free = 1;
}

t_block		*search_ptr(void *ptr)
{
	t_page	*pages;
	t_block	*block;

	pages = first_page();
	while (pages)
	{
		block = pages->blocks;
		while (block)
		{
			if (B_DATA(block) == ptr)
				return (block);
			block = block->next;
		}
		pages = pages->next;
	}
	return (NULL);
}

void		my_free(void *ptr)
{
	t_block		*searched;
	t_page		*page;

	if (!ptr)
		return ;

	searched = search_ptr(ptr);
	if (searched)
	{
		free_block(searched);
		page = page_from_block(searched);
		clean_page(page);
	}
}
