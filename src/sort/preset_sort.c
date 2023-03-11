/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/11 18:09:01 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(int max_value, t_list **list_a, t_list **list_b)
{
	int	times;
	int	i;

	move_index_bottom(list_a, max_value, PRINT_A);
	i = 0;
	times = max_value - 2;
	while (i < times)
	{
		push_list(list_a, list_b, PRINT_B);
		i++;
	}
}
