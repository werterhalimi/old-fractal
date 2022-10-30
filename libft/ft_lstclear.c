/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:31:30 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/18 21:13:01 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lsts, void (*del)(void *))
{
	t_list	*lst;

	while (*lsts)
	{
		lst = *lsts;
		*lsts = lst->next;
		del(lst->content);
		free(lst);
	}
}
