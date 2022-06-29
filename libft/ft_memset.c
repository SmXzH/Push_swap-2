/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:19:53 by szhakypo          #+#    #+#             */
/*   Updated: 2022/02/01 17:18:55 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*b;

	b = (unsigned char *)s;
	while (len)
	{
		b[--len] = (unsigned char)c;
	}
	return (s);
}
