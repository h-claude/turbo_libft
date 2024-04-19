/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:54:15 by hclaude           #+#    #+#             */
/*   Updated: 2024/04/19 23:32:49 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* 
 * Fills the first 'n' bytes of the memory 
 * area pointed to by 's' with the constant byte 'c'.
 * @param s The memory area to fill.
 * @param c The constant byte.
 * @param n The number of bytes to fill.
 * @return A pointer to the memory area 's'.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	char	*target;

	target = s;
	i = 0;
	while (n != 0)
	{
		target[i] = c;
		n--;
		i++;
	}
	return (target);
}
