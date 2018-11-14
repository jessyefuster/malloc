/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyefuster <jessyefuster@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 18:36:41 by jfuster           #+#    #+#             */
/*   Updated: 2018/11/14 15:18:18 by jessyefuster     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

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

void		*space_left_after(t_page *page, t_block *block, size_t size)
{
	void			*start;
	void			*end;

	start = B_AFTER(block);
	end = (block->next ? (void *)(block->next) : P_AFTER(page));
	if ((size_t)(end - start) >= size)
		return (start);
	return (NULL);
}

void		*space_left(t_page *page, size_t size)
{
	void			*start;
	void			*end;
	void			*space;
	t_block			*block;

	block = page->blocks;
	if (!block)
	{
		start = P_DATA(page);
		end = P_AFTER(page);
		if ((size_t)(end - start) >= size)
			return (start);
	}
	else
	{
		while (block)
		{
			if ((space = space_left_after(page, block, size)))
				return (space);
			block = block->next;
		}
	}
	return (NULL);
}

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
