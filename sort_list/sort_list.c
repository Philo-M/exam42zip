/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:20:19 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/22 21:21:40 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int	cmp(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		*swap;
	t_list	*first;

	first = lst;
	while (lst->next)
	{
		if (!cmp(*(int *)lst->data, *(int *)lst->next->data))
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = first;
		}
		else 
			lst = lst->next;
	}
	return (first);
}


int	main(void)
{
	t_list	*list;
	t_list	*first;
	int		i;
	int		j;
	int		k;
	int		l;

	k = 3;
	j = 2;
	l = 4;
	i = 1;
	list = malloc(sizeof(t_list *));
	list->data = &k;
	list->next = malloc(sizeof(t_list *));
	list->next->data = &j;
	list->next->next = malloc(sizeof(t_list *));
	list->next->next->data = &l;
	list->next->next->next = malloc(sizeof(t_list *));
	list->next->next->next->data = &i;
	list->next->next->next->next = NULL;
	first = sort_list(list, cmp);
	printf("first %d\n", *(int *)first->data);
	while (list)
	{
		printf("%d\n", *(int *)list->data);
		list = list->next;
	}
	return (0);
}
