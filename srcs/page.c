/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:11:06 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/24 19:11:23 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_page		*alloc_page(size_t pagesize)
{
	size_t	alloc_size;
	t_page	*new_page;

	alloc_size = pagesize;
	if (pagetype_from_pagesize(pagesize) == LARGE)
		alloc_size += P_META_SIZE + B_META_SIZE;
	new_page = mmap(0, alloc_size, PROT_READ | PROT_WRITE, \
				MAP_ANON | MAP_PRIVATE, -1, 0);
	return (new_page);
}

void		add_page(t_page *new_page)
{
	t_page	*ptr;

	ptr = first_page();
	if (!ptr)
		*real_first_page() = new_page;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_page;
	}
}

void		init_page(t_page *page, size_t pagesize)
{
	if (page)
	{
		page->type = pagetype_from_pagesize(pagesize);
		page->size = pagesize;
		page->busy = 0;
		page->blocks = NULL;
		page->next = NULL;
	}
}

t_page		*create_page(size_t pagesize)
{
	t_page	*new_page;

	new_page = alloc_page(pagesize);
	if (new_page)
	{
		init_page(new_page, pagesize);
		add_page(new_page);
	}
	return (new_page);
}
