/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:17:58 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/29 17:24:29 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/mman.h>

# define TINY_ALLOC_SIZE		(size_t)128
# define SMALL_ALLOC_SIZE		(size_t)1024
# define TINY_PAGE_SIZE			(size_t)(getpagesize() * 4)
# define SMALL_PAGE_SIZE		(size_t)(getpagesize() * 32)

# define P_DATA(page)			(void *)(page + 1)
# define B_DATA(block)			(void *)(block + 1)
# define P_AFTER(page)			P_DATA(page) + page->size
# define B_AFTER(block)			B_DATA(block) + block->size

# define P_META_SIZE			sizeof(t_page)
# define B_META_SIZE			sizeof(t_block)

// # define mmap(a, b, c, d, e, f)	NULL

typedef enum		e_pagetype
{
	TINY,
	SMALL,
	LARGE
}					t_pagetype;

typedef struct		s_page
{
	t_pagetype		type;
	size_t			size;
	size_t			busy;

	struct s_block	*blocks;
	struct s_page	*next;
}					t_page;

typedef struct		s_block
{
	size_t			size;
	char			free;

	struct s_block	*next;
}					t_block;

void				*my_malloc(size_t size);


t_block				*create_block(size_t size, t_page *page);
t_block				*search_free_block(size_t size);

/*
**	block.c
*/
t_block				*last_block(t_block *first);
void				init_block(t_block *block, size_t block_size);
t_block				*add_block_in_mem(void *adress);
void				add_block_to_page(t_page *page, t_block *new_block);
t_block				*add_block(t_page *page, size_t block_size);

/*
**	free.c
*/
t_block				*search_ptr(void *ptr);
void				my_free(void *ptr);

/*
**	page.c
*/
t_page				*create_page(size_t pagesize);
t_page				*alloc_page(size_t pagesize);
void				init_page(t_page *page, size_t pagesize);
void				add_page(t_page *new_page);
void				delete_page(t_page *to_del);

/*
**	root.c
*/
t_page				**real_first_page(void);
t_page				*first_page(void);

/*
**	size.c
*/
t_pagetype			pagetype_from_block(size_t block_size);
size_t				pagesize_from_block(size_t block_size);
t_pagetype			pagetype_from_pagesize(size_t pagesize);
size_t				pagesize_from_pagetype(t_pagetype type);
char				*pagetype_str(t_pagetype type);

/*
**	show_mem.c
*/
void				show_alloc_mem(void);

/*
**	tools.c
*/
void				ft_putstr(char *str);
char				*ft_utob(unsigned long long value, int base, char *base_str);
void				ft_put_utob(unsigned long long value, int base, char *base_str);

#endif
