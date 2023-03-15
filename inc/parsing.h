/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:21:38 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/15 17:58:16 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define TRUE 1
# define FALSE 0

# define ERR "Error\n"

void	init_list(t_data *data, char **integers);
void	set_index(int length, t_list *list_a);
int		check_int(char *nbr);
void	check_duplicate(t_list *list_a);

#endif