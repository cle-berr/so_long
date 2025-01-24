/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:33:33 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/22 13:35:06 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*new_elem(t_list *lst, void *(*f)(void *)\
						, void (*del)(void *), t_list **new_list)
{
	void	*content;
	t_list	*new_elem;

	content = f(lst->content);
	if (!content)
	{
		ft_lstclear(new_list, del);
		return (NULL);
	}
	new_elem = ft_lstnew(content);
	if (!new_elem)
	{
		del(content);
		ft_lstclear(new_list, del);
		return (NULL);
	}
	ft_lstadd_back(new_list, new_elem);
	return (new_elem);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!new_elem(lst, f, del, &new_list))
			return (NULL);
		lst = lst->next;
	}
	return (new_list);
}
/*void *double_content(void *content) {
	int *new_value = malloc(sizeof(int));
	if (!new_value)
		return NULL;
	*new_value = (*(int *)content) * 2;
	return new_value;
}

void delete_content(void *content) {
	free(content);
}*/