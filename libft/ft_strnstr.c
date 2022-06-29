/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:43:25 by szhakypo          #+#    #+#             */
/*   Updated: 2022/02/03 23:12:57 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	char	*hay;

	i = 0;
	c = ft_strlen(needle);
	hay = (char *)haystack;
	if (*needle == 0)
		return (hay);
	while (hay[i] && (i + c) <= len)
	{
		if (hay[i] == *needle)
			if (ft_strncmp(&hay[i], needle, ft_strlen(needle)) == 0)
				return (&hay[i]);
		i++;
	}
	return (NULL);
}
