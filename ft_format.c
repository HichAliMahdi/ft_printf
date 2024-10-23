/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:39:35 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/23 14:43:05 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char format, va_list args, int fd)
{
	int	len;

	len = 0;
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), fd);
		len++;
	}
	else if (format == 's')
	{
		len += ft_putstr_fd(va_arg(args, char *), fd);
	}
	else if (format == 'p')
	{
		len += ft_putptr(va_arg(args, void *), fd);
	}
	else if (format == 'd' || format == 'i')
	{
		len += ft_putnbr_fd(va_arg(args, int), fd);
	}
	else if (format == 'u')
	{
		len += ft_unsnbr(va_arg(args, unsigned int), fd);
	}
	else if (format == 'x')
	{
		len += ft_lhex(va_arg(args, unsigned int), fd);
	}
	else if (format == 'X')
	{
		len += ft_uhex(va_arg(args, unsigned int), fd);
	}
	else if (format == '%')
	{
		ft_putchar_fd('%', fd);
		len++;
	}
	return (len);
}
