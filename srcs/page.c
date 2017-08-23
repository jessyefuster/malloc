/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:11:06 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/23 15:28:32 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_page		**real_first_page(void)
{
	static t_page	*first = NULL;

	return (&first);
}

t_page		*first_page(void)
{
	return (*real_first_page());
}

t_page		*alloc_page(size_t pagesize)
{
	t_page	*new_page;

	new_page = mmap(0, (sizeof(t_page) + pagesize), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

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
		page->blocks = NULL;
		page->next = NULL;
	}
}

t_page		*create_page(size_t pagesize)
{
	t_page	*new_page;

	new_page = alloc_page(pagesize);
	init_page(new_page, pagesize);
	add_page(new_page);

	return (new_page);
}
