/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:17:58 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/22 18:46:04 by jfuster          ###   ########.fr       */
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

# define P_DATA(page)			(void *)(page + sizeof(page))
// # define B_DATA(b)				NULL

typedef enum		e_pagetype
{
	TINY,
	SMALL,
	LARGE
}					t_pagetype;

typedef struct		s_page
{
	t_pagetype		type;

	struct s_block	*first;
	struct s_page	*next;
}					t_page;

typedef struct		s_block
{
	size_t			size;

	struct s_block	*next;
}					t_block;

void				*my_malloc(size_t size);
t_block				*create_new_block(size_t size);
t_block				*search_free_block(size_t size);
t_page				**first_page(void);

#endif
