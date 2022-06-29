/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:27:33 by szhakypo          #+#    #+#             */
/*   Updated: 2022/01/27 17:27:36 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*dest;

	i = size * nmemb;
	dest = malloc(i);
	if (!dest)
		return (0);
	ft_memset(dest, 0, i);
	return (dest);
}
