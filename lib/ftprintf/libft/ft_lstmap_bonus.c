/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:29:33 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/13 15:35:55 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rv;
	t_list	*next;
	void	*next_content;

	rv = NULL;
	while (lst)
	{
		next_content = f(lst->content);
		next = ft_lstnew(next_content);
		if (NULL == next)
		{
			del(next_content);
			ft_lstclear(&rv, del);
			return (NULL);
		}
		ft_lstadd_back(&rv, next);
		lst = lst->next;
	}
	return (rv);
}
