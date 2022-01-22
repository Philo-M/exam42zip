/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:41:24 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/22 12:46:16 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	f(void *data)
{
	int	*i;

	i = (int *)data;
	*i = *i + 1;
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list;

	list = begin_list;
	while (list)
	{
		f(list->data);
		list = list->next;
	}
}

int	main(void)
{
	t_list	*list;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 1;
	j = 2;
	k = 3;
	l = 4;
	list = malloc(sizeof(t_list *));
	list->data = &i;
	list->next = malloc(sizeof(t_list *));
	list->next->data = &j;
	list->next->next = malloc(sizeof(t_list *));
	list->next->next->data = &k;
	list->next->next->next = malloc(sizeof(t_list *));
	list->next->next->next->data = &l;
	list->next->next->next->next = NULL;
	ft_list_foreach(list, f);
	while (list)
	{
		printf("%d\n", *(int *)list->data);
		list = list->next;
	}
	return (0);
}
