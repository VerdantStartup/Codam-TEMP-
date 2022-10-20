/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:08:28 by verdant           #+#    #+#             */
/*   Updated: 2022/10/20 17:39:15 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list *new_head;
	t_list *new_node;
	
	if (!lst || !del)
		return (NULL);
	new_head = 0;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
			{
				ft_lstclear(&new_head, del);
				return (0);
			}
		ft_lstadd_back(&new_head, new_node);
		lst = lst->next;
	}
	return(new_head);
}

// Functionaility:
// - Applying f to the content of the node (lst.node)
// - Adding that node to the end of the list
// - Checking if the allocation of the new node failed and if yes then clearing the whole list