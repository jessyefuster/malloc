/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:32:32 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/24 19:10:39 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void		show_page_info(char *type, void *addr)
{
	ft_putstr(type);
	ft_putstr(" : ");
	ft_put_utob((unsigned long long)addr, 16, "0123456789abcdef");
	ft_putstr("\n");
}

static void		show_block_info(void *start, void *end, size_t size)
{
	ft_put_utob((unsigned long long)start, 16, "0123456789abcdef");
	ft_putstr(" - ");
	ft_put_utob((unsigned long long)end, 16, "0123456789abcdef");
	ft_putstr(" : ");
	ft_put_utob((unsigned long long)size, 10, "0123456789");
	ft_putstr(" octets\n");
}

static void		show_total_info(size_t size)
{
	ft_putstr("Total : ");
	ft_put_utob((unsigned long long)size, 10, "0123456789");
	ft_putstr(" octets\n");
}

void			show_alloc_mem(void)
{
	size_t	total;
	t_page	*page;
	t_block	*block;

	total = 0;
	page = first_page();
	while (page)
	{
		show_page_info(pagetype_str(page->type), P_DATA(page));
		block = page->blocks;
		while (block)
		{
			if (!block->free)
			{
				show_block_info(B_DATA(block), B_AFTER(block) - 1, block->size);
				total += block->size;
			}
			block = block->next;
		}
		page = page->next;
	}
	show_total_info(total);
}
