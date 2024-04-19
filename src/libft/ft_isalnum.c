/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:59:27 by hclaude           #+#    #+#             */
/*   Updated: 2024/04/19 23:05:29 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* 
 * Checks if the passed character is alphanumeric.
 * @param a The character to check.
 * @return Returns 1 if the character is a digit or an alpha, 0 otherwise.
 */
int	ft_isalnum(int a)
{
	return (ft_isdigit(a) || ft_isalpha(a));
}
