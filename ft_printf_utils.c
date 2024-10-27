/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:33:04 by albillie          #+#    #+#             */
/*   Updated: 2024/10/27 06:37:18 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "NULL", 4);
		return (4);
	}
	while (str[i])
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_printnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		return ft_printstr("-2147483648");
	}
	else if (nbr < 0)
	{
		nbr = -nbr;
		ft_printchar('-');
		if (nbr >= 10)
		{
			return (ft_printnbr(nbr / 10) + ft_printchar(nbr % 10 + '0') + 1);
		}
	}
	if (nbr >= 10)
	{
		return ft_printnbr(nbr / 10) + ft_printchar(nbr % 10 + '0');
	}
	return ft_printchar(nbr + '0');
}
/*
int main()
{
	int count;

	count = 0;
	count += ft_printnbr(-2147483648);


	printf("\n%d\n", count);
}*/
