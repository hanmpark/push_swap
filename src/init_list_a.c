/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:29:38 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/03 11:26:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_int(char *nbr)
{
	if (!(ft_isnum(nbr)) ||
		!(ft_atol(nbr) >= -2147483648 && ft_atol(nbr) <= 2147483647))
		return (FALSE);
	return (TRUE);
}

static void	set_list(t_data *data, char **int_str)
{
	int	i;

	i = 0;
	while (int_str && int_str[i])
	{
		if (check_int(int_str[i]) == FALSE)
		{
			ft_freemap(int_str);
			ft_error("Error\nParameter(s) is/are not int\n");
		}
		if (data->a == NULL)
			data->a = ft_lstnew(ft_atoi(int_str[i]));
		else
			ft_lstadd_back(&data->a, ft_lstnew(ft_atoi(int_str[i])));
		free(int_str[i]);
		i++;
	}
}

static void	put_index_to_list(int index, int min, t_list *list_a)
{
	t_list	*current_list;

	current_list = list_a;
	while (current_list)
	{
		if (current_list->number == min)
		{
			current_list->index = index;
			break ;
		}
		current_list = current_list->next;
	}
}

static void	set_index(int length, t_list *list_a)
{
	t_list	*current_list;
	int		min;
	int		index;

	min = current_list->number;
	index = 0;
	while (index < length)
	{
		current_list = list_a;
		while (current_list)
		{
			if (current_list->number < min)
				min = current_list->number;
			current_list = current_list->next;
		}
		put_index_to_list(index, min, list_a);
		index++;
	}
}

void	init_list_a(t_data *data, int length, char **integers)
{
	long	number;
	char	**int_str;
	int		i;

	i = 1;
	while (integers[i])
	{
		int_str = ft_split(integers[i], ' ');
		set_list(data, int_str);
		free(int_str);
		i++;
	}
	set_index(length - 1, &data->a);
}