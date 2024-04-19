/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:50:03 by hclaude           #+#    #+#             */
/*   Updated: 2024/04/19 23:35:37 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* 
 * Iterates the list 'lst' and applies 
 * the function 'f' to the content of each element.
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 * If 'lst' or 'f' is NULL, the function does nothing.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
