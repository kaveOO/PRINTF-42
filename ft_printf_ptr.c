/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 04:56:05 by albillie          #+#    #+#             */
/*   Updated: 2024/10/27 11:01:15 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned long num)
{
	if (num >= 16)
	{
		ft_putnbr_hex(num / 16);
		ft_putnbr_hex(num % 16);
	}
	else
	{
		ft_putchar((num < 10) ? (num + '0') : (num - 10 + 'a'));
	}
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	address;
	size_t			print_length;

	if (ptr == 0)
	{
		return (ft_printstr("(nil)"));
	}
	address = (unsigned long) ptr;
	print_length = 0;

	ft_printstr("0x");
	print_length += 2;
	ft_putnbr_hex(address);

	while (address)
	{
		address /= 16;
		print_length++;
	}
	return (print_length);
}


/* int main()
{
	int *ptr = NULL;

	ft_printf("%p\n", &ptr);
} */
