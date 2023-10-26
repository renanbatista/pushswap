/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:01:15 by r-afonso          #+#    #+#             */
/*   Updated: 2023/10/25 16:40:16 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "get_next_line.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		convert_to_hexa(char *result, unsigned long number);
int		utils(char *str, char type, unsigned long number);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t nmemb, size_t size);

#endif