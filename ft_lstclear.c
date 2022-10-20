/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:59:12 by verdant           #+#    #+#             */
/*   Updated: 2022/10/20 16:18:25 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *head;

	temp = *lst;
	head = *lst;

	while (temp != NULL)
	{
		temp = temp->next;
		del(head->content);
		free(head);
		head = temp;
	}
	*lst = NULL;
}
