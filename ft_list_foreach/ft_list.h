/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:37:30 by imarushe          #+#    #+#             */
/*   Updated: 2022/01/21 20:39:46 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LIST_H_
# define _FT_LIST_H_

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

#endif
