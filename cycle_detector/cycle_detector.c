/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:59:38 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/23 14:36:10 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int	cycle_detector(const t_list *list)
{
	const t_list	*slow;
	const t_list	*fast;

	slow = list;
	fast = list;
	if (!list)
		return (0);
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}

int	main(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*list4;

	list1 = malloc(sizeof(t_list *));
	list2 = malloc(sizeof(t_list *));
	list3 = malloc(sizeof(t_list *));
	list4 = malloc(sizeof(t_list *));


	list1->next = list2;
	list2->next = list3;
	list3->next = list4;
	list4->next = list3;
	printf("%d\n", cycle_detector(list1));
	return (0);
}

