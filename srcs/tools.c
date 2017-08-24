/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:09:26 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/24 19:12:43 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdlib.h>

static size_t	ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str)
		str++;
	return (str - tmp);
}

void			ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

static int		ft_len_num_unsigned(unsigned long long value, int base)
{
	int		len;

	len = 0;
	while (value / base > 0)
	{
		value /= base;
		len++;
	}
	return (len + 1);
}

void			ft_put_utob(unsigned long long value, int base, char *base_str)
{
	char	*str;
	int		len;

	len = ft_len_num_unsigned(value, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = base_str[value % base];
		value /= base;
		len--;
	}
	if (base == 16)
		ft_putstr("0x");
	ft_putstr(str);
}
