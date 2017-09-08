/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 11:35:01 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/30 18:56:38 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*str;
	unsigned char		*strsrc;

	str = (unsigned char *)dst;
	strsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		str[i] = strsrc[i];
		i++;
	}
	return (dst);
}

void		reuse_block(t_block *block, size_t new_size)
{
	block->size = new_size;
}

void		*malloc_and_copy(t_block *old, size_t size)
{
	void	*new;

	new = malloc(size);
	ft_memcpy(new, B_DATA(old), MIN(size, old->size));
	free(B_DATA(old));
	return (new);
}

void		*realloc(void *ptr, size_t size)
{
	t_page		*page;
	t_block		*searched;

	if (!ptr)
		return (malloc(size));
	else if (!size)
		free(ptr);
	else if ((searched = search_ptr(ptr)))
	{
		page = page_from_block(searched);
		if (page->type != LARGE && page->type == pagetype_from_block(size) &&
			(size <= searched->size || space_left_after(page, searched, size)))
		{
			reuse_block(searched, size);
			return (ptr);
		}
		else
			return (malloc_and_copy(searched, size));
	}
	return (NULL);
}
