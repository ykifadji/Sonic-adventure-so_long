/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:58:20 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/04 16:24:18 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (count == 4294967295 || size == 4294967295)
		return (0);
	str = malloc(count * size);
	if (!str)
		return (0);
	ft_memset(str, 0, count * size);
	return (str);
}
