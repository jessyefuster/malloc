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

void	*ft_memcpy(void *dst, const void *src, size_t n)
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

void	reuse_block(t_block *ptr, size_t new_size)
{
	ptr->free = 0;
	ptr->size = new_size;
}

void	*my_realloc(void *ptr, size_t size)
{
	void		*realloc;
	t_page		*page;
	t_block		*searched;

	searched = search_ptr(ptr);
	if (!ptr)
		return (my_malloc(size));
	else if (!size)
		my_free(searched);
	else if (searched)
	{
		page = page_from_block(searched);
		if (size <= searched->size || (pagetype_from_block(size) == page->type && searched->next == NULL && space_left(page, size - searched->size)))
		{
			reuse_block(searched, size);
			page->busy += size - searched->size;
			return (ptr);
		}
		else
		{
			realloc = my_malloc(size);
			ft_memcpy(realloc, ptr, MIN(size, searched->size));
			my_free(ptr);
			return (realloc);
		}
	}
	return (NULL);
}