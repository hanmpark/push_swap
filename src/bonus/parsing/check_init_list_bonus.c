/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_list_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:27:25 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/16 22:28:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "parsing_bonus.h"

static void	find_duplicate(t_list *list_a, int number)
{
	t_list	*current_list;
	int		check;

	current_list = list_a;
	check = 0;
	while (current_list)
	{
		if (current_list->number == number && !check)
			check = 1;
		else if (current_list->number == number && check)
			ft_lsterror(&list_a, ERR);
		current_list = current_list->next;
	}
}

/* Checks if there is any duplicate number */
void	check_duplicate_bonus(t_list *list_a)
{
	t_list	*current_list;
	int		number;

	current_list = list_a;
	number = 0;
	while (current_list != NULL)
	{
		number = current_list->number;
		find_duplicate(list_a, number);
		current_list = current_list->next;
	}
}

/* Checks if it is an int */
int	check_int_bonus(char *nbr)
{
	if (!(ft_isnum(nbr)) || \
		!(ft_atol(nbr) >= -2147483648 && ft_atol(nbr) <= 2147483647))
		return (FALSE);
	return (TRUE);
}
