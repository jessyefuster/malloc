/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 12:15:35 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/22 18:45:25 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_page		**first_page(void)
{
	static t_page	*first = NULL;

	return (&first);
}

t_block		*search_free_block(size_t size)
{
	t_page		*pages;

	pages = *first_page();
	while (pages)
	{
		// IF SPACE AVAILABLE IN 
		pages = pages->next;
	}

	return (NULL);
}

t_block		*create_new_block(size_t size)
{
	t_page		*pages;

	pages = *first_page();
	while (pages)
	{
		pages = pages->next;
	}

	return (NULL);
}

// void		*malloc(size_t size)
// {
// 	t_block		*new_block;

// 	new_block = search_free_block(size);
// 	if (!new_block)
// 		new_block = create_new_block(size);
// 	// if (!new_block)
// 	// 	return (NULL);
// 	// return (NULL);
// 	return (mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));
// }