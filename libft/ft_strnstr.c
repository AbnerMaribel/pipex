/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:02:14 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/21 16:34:32 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack)
		return (0);
	i = 0;
	if (*needle == '\0')
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && ((i + j) < len) && needle[j])
			j++;
		if (j == ft_strlen(needle))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
