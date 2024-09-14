/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahle <cnahle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:43:24 by cnahle            #+#    #+#             */
/*   Updated: 2024/06/19 19:23:01 by cnahle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cgetsize(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n = n / 10;
		count ++;
	}
	return (count);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (!str)
	{
		return (NULL);
	}
	ft_bzero(str, size + 1);
	return (str);
}

char	*ft_itoa(int num)
{
	char		*dst;
	int			count;
	int			i;
	long int	n;

	n = num;
	count = cgetsize(n);
	i = 0;
	if (n < 0 || count == 0)
		count++;
	dst = ft_strnew(count);
	if (n < 0)
	{
		n *= -1;
		dst[0] = '-';
		i++;
	}
	while (count > i)
	{
		dst[--count] = (n % 10) + '0';
		n /= 10;
	}
	return (dst);
}
