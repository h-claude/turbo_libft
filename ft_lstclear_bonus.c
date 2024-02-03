/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:32:58 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/01 14:31:08 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst && (*del))
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, (*del));
			*lst = temp;
		}
	}
	lst = NULL;
}
