/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 07:46:30 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/11 08:10:22 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_size(char const *s, unsigned int start, size_t len)
{
	int	size;

	size = ft_strlen(s) - start;
	while ((size_t)size > len)
		size--;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (0);
	if (*s == 0 || ft_strlen(s) <= (int)start)
		return (ft_strdup(""));
	str = malloc((ft_size(s, start, len) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		if (start == i)
		{
			j = 0;
			while (len-- && s[i])
				str[j++] = s[i++];
			return (str);
		}
		i++;
	}
	return (0);
}
