/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:57:44 by hclaude           #+#    #+#             */
/*   Updated: 2024/09/30 18:41:20 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* 
 * Allocates (with malloc(3)) and returns a new element. 
 * The variable 'content' is initialized with 
 * the value of the parameter 'content'. 
 * The variable 'next' is initialized to NULL.
 * @param content The content to create the new element with.
 * @return The new element. NULL if the allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*tab;

	tab = ft_calloc(1, sizeof(t_list));
	if (!tab)
		return (NULL);
	tab->content = ft_strdup(content);
	if (!tab->content)
		return (free(tab), NULL);
	tab->next = NULL;
	return (tab);
}
