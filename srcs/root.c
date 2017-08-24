/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:05:27 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/24 18:05:50 by jfuster          ###   ########.fr       */
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
