/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:09:33 by moajili           #+#    #+#             */
/*   Updated: 2024/04/19 23:31:51 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* 
 * Returns a pointer to a new string 
 * which is a duplicate of the string 's', 
 * considering only the first 'n' characters. 
 * Memory for the new string is obtained with malloc(3), 
 * and can be freed with free(3).
 * @param s The string to duplicate.
 * @param n The maximum number of characters to be copied from 's'.
 * @return A pointer to the duplicated string. 
 * It returns NULL if 's' is NULL or if insufficient memory was available.
 */
char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len < n)
		n = len;
	dup = (char *)ft_calloc(n + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, n);
	return (dup);
}
