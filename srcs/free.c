/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 12:11:07 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/30 18:57:14 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int			page_is_free(t_page *page)
{
	t_block		*block;

	block = page->blocks;
	while (block)
	{
		if (block->free == 0)
			return (0);
		block = block->next;
	}

	return (1);
}

void		unmap_page(t_page *page)
{
	size_t		unmap_size;
	
	delete_page(page);
	unmap_size = page->size;
	if (pagetype_from_pagesize(page->size) == LARGE)
		unmap_size += P_META_SIZE + B_META_SIZE;
	munmap((void *)page, unmap_size);
}

/*
**	This function checks if pages are empty to unmap them
**	Won't unmap an empty page if it's the only one existing
*/
void		clean_pages(t_pagetype pagetype)
{
	t_page		*pages;
	char		first;

	first = 1;
	pages = first_page();
	while (pages)
	{
		if (pages->type == pagetype)
		{
			if (page_is_free(pages))
			{
				pages->blocks = NULL;
				pages->busy = 0;
			}
			if (first)
				first = 0;
			else
				if (page_is_free(pages))
					unmap_page(pages);
		}
		pages = pages->next;
	}
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
		searched->free = 1;
		page = page_from_block(searched);
		if (page->type == LARGE)
			unmap_page(page);
		else
			clean_pages(page->type);
	}
}
