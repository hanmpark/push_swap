/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:36:53 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/15 17:25:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(const char *error_message)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd((char *)error_message, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(1);
}
