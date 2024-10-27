/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:02:36 by albillie          #+#    #+#             */
/*   Updated: 2024/10/27 06:40:05 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "LIBFT-42/libft.h"


int	ft_format_handler(va_list args, char str)
{
	size_t	print_length;

	print_length = 0;
	if (str == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (str == 's')
		print_length += ft_printstr(va_arg(args, char *));
/* 	else if (str == 'p')
		print_length += // Function for pointer adress here
	else if (str == 'i' || str == 'd')
		print_length += ft_printnbr(va_arg(args, int));
	else if (str == 'u')
		print_length += // Print unsigned decimal integer need function
	else if (str == 'x')
		print_length += // Print unsigned in lowercase hexadecimal
	else if (str == 'X')
		print_length += // Print unsigned in uppercase hexadecimal
	else if (str == "%%")
		print_length += write(1, '%', 1);
 */
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	print_length;
	va_list	args;


	i = 0;
	print_length = 0;
	va_start(args, str);

	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_format_handler(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

int main()
{
	ft_printf("%d", "            j'adore !");
}
