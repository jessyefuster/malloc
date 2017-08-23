/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:17:58 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/23 15:17:29 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/mman.h>

# define TINY_ALLOC_SIZE	128
# define SMALL_ALLOC_SIZE	1024
# define TINY_PAGE_SIZE		getpagesize() * 2
# define SMALL_PAGE_SIZE	getpagesize() * 16

# define P_DATA(page)			(void *)(page + 1)
# define B_DATA(block)			(void *)(block + 1)

typedef enum		e_pagetype
{
	TINY,
	SMALL,
	LARGE
}					t_pagetype;

typedef struct		s_page
{
	t_pagetype		type;

	struct s_block	*blocks;
	struct s_page	*next;
}					t_page;

typedef struct		s_block
{
	size_t			size;

	struct s_block	*next;
}					t_block;

void				*my_malloc(size_t size);


t_block				*create_block(size_t size, t_page *page);
t_block				*search_free_block(size_t size);

/*
**	page.c
*/
t_page				**real_first_page(void);
t_page				*first_page(void);
t_page				*create_page(size_t pagesize);
t_page				*alloc_page(size_t pagesize);
void				add_page(t_page *new_page);

/*
**	block.c
*/
t_block				*add_block_in_page(t_page *page, size_t block_size);

/*
**	size.c
*/
t_pagetype			pagetype_from_block(size_t block_size);
size_t				pagesize_from_block(size_t block_size);
size_t				pagetype_from_pagesize(size_t pagesize);
size_t				pagesize_from_pagetype(t_pagetype type);

#endif