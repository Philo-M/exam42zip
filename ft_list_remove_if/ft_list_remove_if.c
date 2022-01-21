/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:54:10 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/21 14:45:14 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

int	cmp(void *data, void *data_ref)
{
	if (data == data_ref)
		return (0);
	return (1);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;
	t_list	*list;

	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
	}
	list = *begin_list;
	while (list && list->next)
	{
		if (!cmp(list->next->data, data_ref))
		{
			temp = list->next;
			list->next = list->next->next;
			free(temp);
		}
		else if (list->next)
			list = list->next;
	}
}

int	main(void)
{
	int		i;
	int		j;
	t_list	*list;

	i = 1;
	j = 2;
	list = malloc(sizeof(t_list *));
	list->data = &i;
	list->next = malloc(sizeof(t_list *));
	list->next->data = &j;
	list->next->next = malloc(sizeof(t_list *));
	list->next->next->data = &i;
	list->next->next->next = malloc(sizeof(t_list *));
	list->next->next->next->data = &j;
	list->next->next->next->next = NULL;
	ft_list_remove_if(&list, &i, cmp);
	while (list)
	{
		printf("%d\n", *(int *)list->data);
		list = list->next;
	}
	return (0);
}
