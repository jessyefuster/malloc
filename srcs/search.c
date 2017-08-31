/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 18:36:41 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/30 18:38:09 by jfuster          ###   ########.fr       */
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
			if (B_DATA(block) == ptr && block->free == 0)
				return (block);
			block = block->next;
		}
		pages = pages->next;
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
