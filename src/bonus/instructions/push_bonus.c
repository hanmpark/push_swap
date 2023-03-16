/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:41:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 19:23:47 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap_bonus.h"
#include "../../../inc/instructions_bonus.h"

/* Push a list to the top of the other chained list */
void	push_list(t_list **from_list, t_list **to_list)
{
	t_list	*current;
	t_list	*next;

	if (!*from_list)
		return ;
	current = *from_list;
	next = current->next;
	ft_lstadd_front(to_list, ft_lstnew(current->number, current->index));
	ft_lstdelone(*from_list);
	*from_list = next;
}
