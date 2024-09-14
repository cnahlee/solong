/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:36:23 by cnahle            #+#    #+#             */
/*   Updated: 2024/08/09 18:01:11 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)str++ == (unsigned char)c)
			return ((void *)(unsigned char *)str - 1);
	}
	return (NULL);
}
