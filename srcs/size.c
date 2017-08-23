/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:14:23 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/23 15:16:18 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_pagetype		pagetype_from_block(size_t block_size)
{
	if (block_size <= TINY_ALLOC_SIZE)
		return (TINY);
	else if (block_size <= SMALL_ALLOC_SIZE)
		return (SMALL);
	return (LARGE);
}

size_t			pagesize_from_block(size_t block_size)
{
	if (block_size <= TINY_ALLOC_SIZE)
		return (TINY_PAGE_SIZE);
	else if (block_size <= SMALL_ALLOC_SIZE)
		return (SMALL_PAGE_SIZE);
	return (block_size);
}

size_t			pagetype_from_pagesize(size_t pagesize)
{
	if (pagesize == TINY_PAGE_SIZE)
		return (TINY);
	else if (pagesize == SMALL_PAGE_SIZE)
		return (SMALL);
	return (LARGE);
}

size_t			pagesize_from_pagetype(t_pagetype type)
{
	if (type == TINY)
		return (TINY_PAGE_SIZE);
	else if (type == SMALL)
		return (SMALL_PAGE_SIZE);
	else
		return (0);
}