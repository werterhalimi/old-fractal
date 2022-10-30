/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:55:03 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/18 21:12:28 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	b(t_list **buffer, t_list **current, t_list **ret, t_list **lst)
{
	*buffer = *current;
	*ret = *current;
	*lst = (*lst)->next;
}

static void	bullshit2(t_list **buffer, t_list **current, t_list **lst)
{
	(*buffer)->next = *current;
	*buffer = *current;
	*lst = (*lst)->next;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buffer;
	t_list	*current;
	t_list	*ret;

	buffer = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		current = ft_lstnew(f(lst->content));
		if (!current)
		{
			ft_lstclear(&buffer, del);
			return (0);
		}
		if (!buffer)
		{
			b(&buffer, &current, &ret, &lst);
			continue ;
		}
		bullshit2(&buffer, &current, &lst);
	}
	current->next = 0;
	return (ret);
}
