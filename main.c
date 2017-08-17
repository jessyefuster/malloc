/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:09:37 by jfuster           #+#    #+#             */
/*   Updated: 2017/08/17 19:20:08 by jfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	char	*str;
	size_t	size = 5;

	str = (char *)malloc(sizeof(char) * size);

	size_t	i = 0;
	while (i < size)
	{
		str[i] = '*';
		i++;
	}
	str[i] = 0;

	printf("%s\n", str);

	printf("%d\n", str);

	return (0);
}