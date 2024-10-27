/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:04:20 by albillie          #+#    #+#             */
/*   Updated: 2024/10/27 06:33:46 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(int c);
int 	ft_printstr(char *str);
int		ft_printnbr(int nbr);
void	ft_putstr_fd(char *s, int fd);

#endif
