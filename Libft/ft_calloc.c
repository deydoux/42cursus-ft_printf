/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:30:49 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/15 08:56:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*ptr;

	if (!size && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	bytes = nmemb * size;
	ptr = malloc(bytes);
	if (ptr)
		ft_bzero(ptr, bytes);
	return (ptr);
}
